#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "socket.h"

class ClientSocket: public Socket{
    private:
        struct sockaddr_in peer;
        
    public:
        //ip, port
        ClientSocket(std::string, int);
        //new socket, new addr
        ClientSocket(int, struct sockaddr_in);
        virtual ~ClientSocket();
        void Connect();
};

#endif
