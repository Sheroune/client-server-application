all: client server

.PHONY: client
client: socket.cpp socket.h client.cpp client.h client_main.cpp
	g++ -Wall -Werror -pedantic socket.cpp client.cpp client_main.cpp -o client

.PHONY: server
server: socket.cpp socket.h client.cpp client.h server.cpp server.h server_main.cpp
	g++ -Wall -Werror -pedantic server_main.cpp server.cpp client.cpp socket.cpp -o server

.PHONY: clean
clean:
	$(RM) client server
