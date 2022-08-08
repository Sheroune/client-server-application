#include <iostream>
#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#include "client.h"
#include "server.h"

#define QUEUE 5


ServerSocket::ServerSocket(int port){
	if((sockfd=socket(AF_INET, SOCK_STREAM, 0)) == -1){
	    perror("socket()");
	    exit(1);
	}
	good = true;

	memset(&self, 0x00, sizeof(struct sockaddr_in));
	self.sin_family      = AF_INET;
	self.sin_port        = htons(port);
	self.sin_addr.s_addr = INADDR_ANY;
}

ServerSocket::~ServerSocket(){}

void ServerSocket::Bind(){
	if(bind(sockfd, (struct sockaddr*)&self, sizeof(struct sockaddr_in)) == -1){
    	perror("bind()");
    	exit(1);
  	}
}

void ServerSocket::Listen(){
	if(listen(sockfd, QUEUE) == -1){
    	perror("listen()");
    	exit(1);
  	}
}

ClientSocket ServerSocket::Accept(){
	int cli_sock;
	struct sockaddr_in cli_addr;

    socklen_t addrlen = sizeof(struct sockaddr_in);
    if((cli_sock=accept(sockfd, (struct sockaddr*)&cli_addr, &addrlen)) == -1){
    	perror("accept()");
    }
	std::cout << "SERVER: connection from ";
	std::cout << inet_ntoa(cli_addr.sin_addr) << std::endl;
	ClientSocket m(cli_sock, cli_addr);
	return m;
}
