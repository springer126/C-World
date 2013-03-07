#include <iostream>
using namespace std;
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/wait.h>
void req_proc(int s,char*);

void fn(int sig){
    int pid = wait(NULL);
    cout << "child   " << pid << "   clear" << endl;
    signal(SIGCHLD,fn);    

}
int main()
{
    if(signal(SIGCHLD,fn)==SIG_ERR){
        cout << "capture signal error" << endl;
        exit(0);
	}
	

	int fd = socket(AF_INET,SOCK_STREAM,0);
        if(fd<0)
        {
                cout << "create socket error!" << endl;
                return 0;
        }    
        
        struct sockaddr_in serveraddr;
socklen_t len = sizeof(serveraddr);
memset(&serveraddr,0,len);
serveraddr.sin_family=AF_INET;
serveraddr.sin_addr.s_addr=INADDR_ANY;
short port;
cout << "enter a port:" ;
cin >> port;
serveraddr.sin_port=htons(port);

int ret = bind(fd,(struct sockaddr*)&serveraddr,len);
if(ret !=0)
{
    cout << "bind error!" << endl;
    close(fd);
    exit(0);
}

int lis;
lis = listen(fd,5);
if(lis < 0)
{
    cout << "listen error!" <<endl;
    cout << errno << endl;
    exit(0);
}
cout << "listen() success!" << endl;

struct sockaddr_in clientaddr;
len = sizeof(clientaddr);
while(1)
{
    memset(&len,0,len);
//-----invoke accept----------------
cout << "server is running............" << endl;
int cfd = accept(fd,(struct sockaddr*)&clientaddr,&len);
if(cfd == -1)
{
    cout << "accept() failed"<< endl;
    exit(0);
}
if(cfd < 0)
continue;
//print address message of client!
char ip[16];

memset(ip,0,16);
inet_ntop(AF_INET,&clientaddr.sin_addr,ip,16);
cout << "get connection from " << ip << ":";
cout << clientaddr.sin_port << endl;
int pid = fork();
if(pid ==0)
    {
    //read(),write()
    close(fd);
    req_proc(cfd,ip);
    //close().
    close(cfd);
    exit(0);
    }
    close(cfd);
    }
}


void req_proc(int cfd,char* ip)
{
char buf[100];
int len =0;
while(1)
{
    memset(buf,0,sizeof(buf));
    len = read(cfd,buf,100);
    if(len == 0) break;
    cout << buf <<'['<< ip <<']'<< endl;
    strcat(buf,"[back from server]");
    write(cfd,buf,strlen(buf));
}
}

