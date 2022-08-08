#include <iostream>
#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <arpa/inet.h>
#include "client.h"

ClientSocket::ClientSocket(std::string ip, int port){
    if((sockfd=socket(AF_INET, SOCK_STREAM, 0)) == -1){
        perror("socket()");
        exit(1);
    }

    memset(&peer, 0x00, sizeof(struct sockaddr_in));
    peer.sin_family      = AF_INET;
    peer.sin_port        = htons(port);
    peer.sin_addr.s_addr = inet_addr(ip.c_str());

    good = true;
}

ClientSocket::ClientSocket(int sock, struct sockaddr_in addr){
    sockfd = sock;
    peer = addr;
    good = true;
}

ClientSocket::~ClientSocket(){}

void ClientSocket::Connect(){
    if(connect(sockfd, (struct sockaddr*)&peer, sizeof(struct sockaddr_in)) == -1){
        perror("connect()");
        exit(1);
    }
}
