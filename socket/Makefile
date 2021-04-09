PORT	=	9000
SERVER = server
CLIENT = client
ADDR	=	127.0.0.1

all	: 
	clang client.c  -o client_exec
	clang server.c  -o server_exec

$(SERVER)	:
	./server_exec $(PORT)

$(CLIENT)	:
	./client_exec $(ADDR) $(PORT)
