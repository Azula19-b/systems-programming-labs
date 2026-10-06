// Name: Bahar Ozer
// compile: gcc rec09svr.c -o rec09svr
// usage  : ./rec09svr port

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
 
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "usage: %s <port>\n", argv[0]);
		return EXIT_FAILURE;
	}

	int listenfd = 0, connfd = 0, cli_size, portno;

	struct sockaddr_in serv_addr, cli_addr;

	char sendBuff[1025];  
 
	if ((listenfd = socket(  AF_INET, SOCK_STREAM, 0  )) == -1) // Create TCP socket using IPv4
	{
		printf("socket error\n");
		exit(EXIT_FAILURE);
	}

	memset(&serv_addr, '0', sizeof(serv_addr));
	memset(sendBuff, '0', sizeof(sendBuff));

	serv_addr.sin_family = AF_INET;    
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); 
	portno = atoi(argv[1]);
	serv_addr.sin_port = htons(portno);  
  
        int on = 1; //Enable option flag
        setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));//Allow port reuse

	if (bind( listenfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)  ) == -1)// Bind socket to port
	{
		printf("bind error\n");
		exit(EXIT_FAILURE);
	}


	if (listen(  listenfd, 10  ) == -1)// Listen for incoming connections (queue size is  10)
	{
		printf("listen error\n");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		cli_size = sizeof(cli_addr);
		if ((connfd = accept(  listenfd, (struct sockaddr *)&cli_addr, (socklen_t *)&cli_size  )) == -1)// Accept client connection
		{
			printf("accept error\n");
			exit(EXIT_FAILURE);
		}

		strcpy(sendBuff, "Server Message: SUCCESS\n");
		write(connfd, sendBuff, strlen(sendBuff));// Send message to client

		close(connfd);  // Close connection with client
		sleep(1);
	} 
 
	return 0;
}
