#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "socket.h"

Socket::Socket(){
    sockfd=-1;
    good = false;
}

Socket::~Socket(){
    if(good) close(sockfd);
}

void Socket::Shutdown(){
    if(shutdown(sockfd, SHUT_RDWR) == -1){
        perror("Shutdown()");
    }
}

Socket& Socket::Read(char*data, std::streamsize size){
    do{
        int ret;
        memset(data,0x00,size);

        // reading data
        if((ret=recv(sockfd, data, size-1, 0)) == -1){
            perror("Read()");
            break;
        }
        std::cout << "CLIENT: received " + std::to_string(ret) + " bytes of data = ";
        std::cout << data << std::endl;
        //printf("CLIENT: received %d bytes of data=%s\n", ret, data);
    }while(0);
    return *this;
}

Socket& Socket::Write(const char*data, std::streamsize size){
    if(send(sockfd, data, size, 0) == -1){
        perror("Write()");
    }
    return *this;
}

Socket& Socket::operator>>(std::string&rhs){
    std::string s = rhs;
    char c[SIZE];
    strcpy(c, s.c_str());
    Read(c, SIZE);

    return *this;
}

Socket& Socket::operator<<(const std::string&rhs){
    std::string s = rhs;
    Write(s.c_str(), rhs.length());
    return *this;
}