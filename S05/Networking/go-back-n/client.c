#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define LOCALHOST "127.0.0.1"
#define BUFFER_SIZE 256

#define TIMEOUT_SEC 2
#define MAX_RETRIES 5
#define NUM_PACKETS 5

#define WINDOW_SIZE 3

typedef struct
{
    int seq_num;
    int data;
} Packet;

typedef struct
{
    int ack_num;
} ACK;

struct sockaddr_in create_address()
{
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = inet_addr(LOCALHOST);

    return addr;
}

void error_check(int x, char success[])
{
    if (x < 0)
    {
        perror("something went wrong");
        exit(1);
    }
    else
    {
        printf("%s\n", success);
    }
}

int main()
{
    // 1. Create client socket
    int s = socket(AF_INET, SOCK_DGRAM, 0);
    error_check(s, "socket created");

    // Set socket timeout
    struct timeval timeout = { TIMEOUT_SEC, 0 };
    setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

    // 2. Build server address structure
    struct sockaddr_in server_address = create_address();
    socklen_t server_len = sizeof(server_address);

    // 3. Send packets
    int base = 1;
    int next_seq = 1;
    int retries = 0;

    while (base <= NUM_PACKETS)
    {
        // Send
        while (next_seq < base + WINDOW_SIZE && next_seq <= NUM_PACKETS)
        {
            Packet packet;
            packet.seq_num = (next_seq - 1) % (WINDOW_SIZE + 1);
            packet.data = next_seq;

            printf("Sending data %d (seq_num = %d)\n", packet.data, packet.seq_num);
            int status = sendto(s, &packet, sizeof(packet), 0, (struct sockaddr *)&server_address, server_len);
            if (status < 0)
            {
                perror("Send failed");
            }
            next_seq++;
        }

        // Wait
        ACK ack;
        int status = recvfrom(s, &ack, sizeof(ack), 0, (struct sockaddr *)&server_address, &server_len);
        
        if (status < 0)
        {
            printf("Timeout! No ACK received. Going back to data %d...\n", base);
            retries++;
            
            if (retries >= MAX_RETRIES)
            {
                printf("Failed after %d retries.\n", MAX_RETRIES);
                break;
            }
            
            next_seq = base;
        }
        else
        {
            int expected_seq = (base - 1) % (WINDOW_SIZE + 1);
            
            if (ack.ack_num == expected_seq)
            {
                printf("ACK received for data %d (ack_num = %d)\n", base, ack.ack_num);
                base++;
                retries = 0;
                printf("---\n");
            }
            else
            {
                printf("Wrong ACK received (expected %d, got %d). Going back to data %d...\n", expected_seq, ack.ack_num, base);
                retries++;
                
                if (retries >= MAX_RETRIES)
                {
                    printf("Failed after %d retries.\n", MAX_RETRIES);
                    break;
                }
                
                // Going back
                next_seq = base;
            }
        }
    }

    // 4. Close socket
    close(s);

    return 0;
}
