#pragma once

#ifndef SOCKET_H

#define SOCKET_H
#define SIZE 1024

#include <cstring>

class Socket{
    protected:
        bool good;
        int sockfd;

    public:
        Socket();
        virtual ~Socket();
        
        Socket& Read(char *, std::streamsize);
        Socket& Write(const char *, std::streamsize);

        Socket& operator>>(std::string&rhs);
        Socket& operator<<(const std::string&rhs);

        void Shutdown();
};

#endif
