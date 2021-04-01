PORT	=	9000
SERVER = server
CLIENT = client
ADDR	=	127.0.0.1

all	: $(SERVER) $(CLIENT)


$(SERVER)	:
	clang server.c 
	./a.out $(PORT)

$(CLIENT)	:
	clang client.c 
	./a.out $(ADDR) $(PORT)
