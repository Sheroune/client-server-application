#include <iostream>
#include "socket.h"
#include "server.h"

int main(){
    ServerSocket server(3490);
	server.Bind();
	server.Listen();
	std::string smth;
	while(1){
		ClientSocket a = server.Accept();
		std::cin >> smth;
		a << smth;

        //a.Write(smth.c_str(), smth.length()+1);

		a.Shutdown();
	}
	server.Shutdown();
    return 0;
}
