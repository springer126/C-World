#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>
#include "apue.h"
#include <errno.h>

#define BUFLEN 128
#define QLEN 10

int
initserver(int type, const struct sockaddr *addr, socklen_t alen,
  int qlen)
{
        int fd;
        int err = 0;

        if ((fd = socket(addr->sa_family, type, 0)) < 0)
                return(-1);
        if (bind(fd, addr, alen) < 0) {
                err = errno;
                goto errout;
        }
        if (type == SOCK_STREAM || type == SOCK_SEQPACKET) {
                if (listen(fd, qlen) < 0) {
                        err = errno;
                        goto errout;
                }
        }
        return(fd);

errout:
        close(fd);
        errno = err;
        return(-1);
}

int main()
{
	int s;
	int fd;
	int i = 0;
	int n;
	char buf[BUFLEN];
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	socklen_t length;

	memset(&server_addr,0,sizeof(server_addr));
	memset(&client_addr,0,sizeof(client_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(8888);
//	server_addr.sin_addr.s_addr = inet_addr("192.168.1.101");
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if((s = initserver(SOCK_STREAM,(struct sockaddr *)&server_addr,sizeof(server_addr),QLEN))>0)
	{
			printf("服务器端初始化完毕，开始监听……\n");
	}
	else
	{
			printf("初始化失败!\n");
	}
	
	for(;;)
	{
		if((fd = accept(s,(struct sockaddr *)&client_addr,&length))>=0)
		{
			printf("接受一个请求！\n");
			memset(buf,0,BUFLEN);
			n=recv(fd,buf,BUFLEN,0);
			write(STDOUT_FILENO,buf,n);
			memset(buf,0,BUFLEN);
		//	scanf("%d",&i);
			sprintf(buf,"Server No.: %d\n",++i);
			while(send(fd,buf,strlen(buf),0)==-1)
			{
					printf("Sending....\n");
					sleep(1);
			}
			printf("Sending finished!\n");
			close(fd);	
		}
	}	
	exit(1);
}
