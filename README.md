# Client/Server socket-based application

Small local client/server socket based application  
  
Server can listen to opened port for client connection and then transfer information  
Client can connect to the server, receive information and output it

## Usage

GNUmakefile:  
`make`

Manually:  
Client: `g++ socket.cpp client.cpp client_main.cpp -o client`  
Server: `g++ server_main.cpp server.cpp client.cpp socket.cpp -o server`

Running:  
`./server` to run server and './client' to run client`

> Note: POSIX/SUS facilities are required for successful execution
