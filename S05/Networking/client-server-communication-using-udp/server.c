#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<unistd.h>

#define PORT 8080
#define BUFFER_SIZE 256
#define LOCALHOST inet_addr("127.0.0.1")
#define SERVER "server"
#define CLIENT "client"

void main()
{
	void error_check(int x, char success[])
	{
		if(x<0)
		{
			perror("something went wrong");
			exit(0);
		}
		else
		{
			printf("%s\n",success);
		}
	}

	struct sockaddr_in create_socket_address(char type[])
	{
		struct sockaddr_in socket_address;
		socket_address.sin_family = AF_INET;
		if(strcmp(type, SERVER) == 0)
		{
			socket_address.sin_addr.s_addr = LOCALHOST;
			socket_address.sin_port = htons(PORT);
			return socket_address;
		}
		return socket_address;
	}

	int s = socket(AF_INET, SOCK_DGRAM, 0);
	error_check(s, "server socket created successfully");

	struct sockaddr_in server_address = create_socket_address(SERVER);
	socklen_t len1 = sizeof(server_address);

	int b = bind(s, (struct sockaddr *)&server_address, len1);
	error_check(b, "binding successful");

	printf("UDP Server is listening on port %d...\n", PORT);

	struct sockaddr_in client_address;
	socklen_t len2 = sizeof(client_address);

	char buffer[BUFFER_SIZE] = "";
	char reply[] = "\n ... Hello, this is the Server ...\n";
	int status = -1;

	status = recvfrom(s, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client_address, &len2);
	error_check(status, "message received from client");
	printf("Received from client: %s", buffer);

	status = sendto(s, reply, strlen(reply), 0, (struct sockaddr *)&client_address, len2);
	error_check(status, "reply successfully sent to client");

	printf("\n client-server request-reply process successfully demonstrated using UDP sockets \n .... terminating server .... \n");
	close(s);
}
