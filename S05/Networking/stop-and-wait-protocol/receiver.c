#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_FRAME_SIZE 1024
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
    struct sockaddr_in servaddr, cliaddr;
    Frame frame;
    Ack ack;
    socklen_t len = sizeof(cliaddr);
    int expected_seq = 0;
    int frames_received = 0;
    int frame_count = 0;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        die("socket creation failed");
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // Bind socket
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        die("bind failed");
    }

    int pattern[] = {1, 2, 3, 4, 5};
    int pattern_len = sizeof(pattern) / sizeof(pattern[0]);
    int idx = 0;
    int dropped[5] = {0, 0, 0, 0, 0};

    while (idx < pattern_len)
    {
        recvfrom(sockfd, &frame, sizeof(frame), 0, (struct sockaddr *)&cliaddr, &len);
        printf("\nReceiver: Got Frame %d\n", frame.seq);

        if (frame.seq == pattern[idx])
        {
            if ((frame.seq == 3 || frame.seq == 5) && !dropped[frame.seq - 1])
            {
                printf("Receiver: Intentionally dropping ACK for Frame %d\n", frame.seq);
                dropped[frame.seq - 1] = 1;
                continue;
            }

            ack.ack = frame.seq;
            sendto(sockfd, &ack, sizeof(ack), 0, (struct sockaddr *)&cliaddr, len);
            printf("Receiver: Sent ACK for Frame %d\n", frame.seq);
            idx++;
        }
    }

    close(sockfd);
    printf("Receiver: All frames received successfully\n");
    return 0;
}
