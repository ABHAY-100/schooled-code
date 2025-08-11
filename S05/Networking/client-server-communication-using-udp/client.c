#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define LOCALHOST inet_addr("127.0.0.1")
#define BUFFER_SIZE 256

void main()
{
    void error_check(int x, char success[])
    {
        if (x < 0)
        {
            perror("something went wrong");
            exit(0);
        }
        else
        {
            printf("%s\n", success);
        }
    }

    int s = socket(AF_INET, SOCK_DGRAM, 0);
    error_check(s, "socket created");

    struct sockaddr_in socket_address;
    socket_address.sin_family = AF_INET;
    socket_address.sin_addr.s_addr = LOCALHOST;
    socket_address.sin_port = htons(PORT);

    char buffer[BUFFER_SIZE] = "";
    char request[] = "\n ... Hello, this is the Client ... \n";
    socklen_t len = sizeof(socket_address);
    int status = 0;

    status = sendto(s, request, strlen(request), 0, (struct sockaddr *)&socket_address, len);
    error_check(status, "message successfully sent to server");

    status = recvfrom(s, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&socket_address, &len);
    error_check(status, "reply received from server");
    printf("Received from server: %s", buffer);

    printf(" client-server request-reply process successfully demonstrated using UDP sockets \n .... terminating socket .... \n");
    close(s);
}
