#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>

#define PORT 8080
#define MAX_FRAME_SIZE 1024
#define TIMEOUT_SEC 3
#define MAX_FRAMES 5

typedef struct
{
    int seq;
    char data[MAX_FRAME_SIZE];
} Frame;

typedef struct
{
    int ack;
} Ack;

void die(const char *msg)
{
    perror(msg);
    exit(1);
}

int main()
{
    int sockfd;
    struct sockaddr_in servaddr;
    Frame frame;
    Ack ack;
    socklen_t len = sizeof(servaddr);
    int current_seq = 0;
    fd_set fds;
    struct timeval tv;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        die("socket creation failed");
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    for (int i = 0; i < MAX_FRAMES; i++)
    {
        // Prepare frame
        frame.seq = current_seq;
        snprintf(frame.data, MAX_FRAME_SIZE, "Frame %d data", i);

        while (1)
        {
            // Send frame
            sendto(sockfd, &frame, sizeof(frame), 0, (const struct sockaddr *)&servaddr, len);
            printf("Sender: Sent frame with seq %d\n", current_seq);

            // Wait for ACK with timeout
            FD_ZERO(&fds);
            FD_SET(sockfd, &fds);
            tv.tv_sec = TIMEOUT_SEC;
            tv.tv_usec = 0;

            int ready = select(sockfd + 1, &fds, NULL, NULL, &tv);
            if (ready < 0)
            {
                die("select error");
            }
            else if (ready == 0)
            {
                printf("Sender: Timeout, resending frame with seq %d\n", current_seq);
                continue;
            }

            // Receive ACK
            recvfrom(sockfd, &ack, sizeof(ack), 0, (struct sockaddr *)&servaddr, &len);
            printf("Sender: Received ACK %d\n", ack.ack);

            if (ack.ack == current_seq)
            {
                printf("Sender: ACK confirmed for seq %d\n", current_seq);
                current_seq = 1 - current_seq; // Toggle seq
                break;
            }
            else
            {
                printf("Sender: Incorrect ACK, resending\n");
            }
        }
    }

    close(sockfd);
    printf("Sender: All frames sent successfully\n");
    return 0;
}
