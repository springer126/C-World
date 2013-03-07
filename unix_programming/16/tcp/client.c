#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <stdio.h>
#include "apue.h"
#include <errno.h>


#define MAXSLEEP 32
#define BUFLEN 128

int main()
{
	int s;
	int n;
	int i;
	char buf[BUFLEN];
	struct sockaddr_in server_addr;
	memset(&server_addr,0,sizeof(server_addr));
	server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8888);

	printf("Debug!\n");

    if((inet_pton(AF_INET,"192.168.1.101",&server_addr.sin_addr))==-1)
		printf("Failed! \n");
    //server_addr.sin_addr.s_addr = inet_addr("192.168.1.101");
	s = socket(AF_INET,SOCK_STREAM,0);
	if(connect(s,(struct sockaddr *)&server_addr,sizeof(server_addr))==0)
	{
		printf("连接成功！\n");
		scanf("%d",&i);
		memset(buf,0,BUFLEN);
		sprintf(buf,"Client No.: %d",i);
		send(s,buf,strlen(buf),0);			
		sleep(3);
		memset(buf,0,BUFLEN);
		n = recv(s,buf,BUFLEN,0));
		write(STDOUT_FILENO,buf,n);

	}
	else
	{
			printf("连接失败！\n");
	}

	
	return 0;
}
