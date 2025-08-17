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

typedef struct {
    int seq;
    char data[MAX_FRAME_SIZE];
} Frame;

typedef struct {
    int ack;
} Ack;

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;
    Frame frame;
    Ack ack;
    socklen_t len = sizeof(cliaddr);
    int expected_seq = 0;
    int frames_received = 0;
    int frame_count = 0;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        die("socket creation failed");
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // Bind socket
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        die("bind failed");
    }

    while (frames_received < MAX_FRAMES) {
        // Receive frame
        recvfrom(sockfd, &frame, sizeof(frame), 0, (struct sockaddr *)&cliaddr, &len);
        frame_count++; // Increment frame count
        printf("Receiver: Received frame with seq %d, data: %s (Frame #%d)\n", frame.seq, frame.data, frame_count);

        // Prepare ACK
        ack.ack = frame.seq;

        // Intentionally drop ACK for the second frame
        if (frame_count == 2) {
            printf("Receiver: Intentionally dropping ACK for frame #%d (seq %d)\n", frame_count, frame.seq);
            continue; // Skip sending ACK
        }

        if (frame.seq == expected_seq) {
            // Deliver data
            printf("Receiver: Delivered data: %s\n", frame.data);
            expected_seq = 1 - expected_seq; // Toggle expected seq
            frames_received++;
        } else {
            // Duplicate frame, send ACK but don't deliver
            printf("Receiver: Duplicate frame, sending ACK %d again\n", ack.ack);
        }

        // Send ACK
        sendto(sockfd, &ack, sizeof(ack), 0, (const struct sockaddr *)&cliaddr, len);
        printf("Receiver: Sent ACK %d\n", ack.ack);
    }

    close(sockfd);
    printf("Receiver: All frames received successfully\n");
    return 0;
}
