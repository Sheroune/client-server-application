#include <iostream>

#include "socket.h"
#include "client.h"

#define SIZE 1024

int main(){
    std::string smth;

    ClientSocket client("127.0.0.1", 3490);
    client.Connect();
    client >> smth;

    //char sz[SIZE];
    //client.Read(sz, SIZE);

    return 0;
}
