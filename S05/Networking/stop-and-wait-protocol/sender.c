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

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        die("socket creation failed");
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int pattern[] = {1, 2, 3, 4, 5};
    int pattern_len = sizeof(pattern) / sizeof(pattern[0]);
    for (int i = 0; i < pattern_len; i++)
    {
        frame.seq = pattern[i];
        int attempts = 0;
        while (1)
        {
            printf("\nSender: Sending Frame %d\n", frame.seq);
            sendto(sockfd, &frame, sizeof(frame), 0, (const struct sockaddr *)&servaddr, len);

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
                printf("Sender: No ACK received, retransmitting Frame %d\n", frame.seq);
                continue;
            }

            recvfrom(sockfd, &ack, sizeof(ack), 0, (struct sockaddr *)&servaddr, &len);
            printf("Sender: Received ACK %d\n", ack.ack);

            if (ack.ack == frame.seq)
            {
                printf("Sender: Frame %d successfully transmitted\n", frame.seq);
                break;
            }
        }
    }

    close(sockfd);
    printf("Sender: All frames sent successfully\n");
    return 0;
}
