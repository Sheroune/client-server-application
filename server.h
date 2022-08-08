#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "socket.h"
#include "client.h"

class ServerSocket: public Socket{
    private:
        struct sockaddr_in self;
        
    public:
        //port
        ServerSocket(int);
        virtual ~ServerSocket();
        void Bind();
        void Listen();
        ClientSocket Accept();
};

#endif
