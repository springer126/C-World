server:server.o
	cc server.o -o server

server.o:server.c
	cc -c server.c -o server.o



client:client.o
	cc  client.o -o client

client.o:client.c
	cc  -c client.c -o client.o

clean:
	rm *.o server client
