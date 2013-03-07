#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>

/**
广播与多播只支持UDP协议，因为TCP协议是端到端，这与广播与多播的理念相冲突
广播是局域网中一个主机对所有主机的数据通信，而多播是一个主机对一组特定的主机进行通信.多播可以是因特网，而广播只能是局域网。多播常用于视频电话，网上会议等。
setsockopt设置套接字选项可以设置多播的一些相关信息
IP_MULTICAST_TTL //设置多播的跳数值
IP_ADD_MEMBERSHIP //将主机的指定接口加入多播组，以后就从这个指定的接口发送与接收数据
IP_DROP_MEMBERSHIP //主机退出多播组
IP_MULTICAST_IF //获取默认的接口或设置多播接口
IP_MULTICAST_LOOP //设置或禁止多播数据回送，即多播的数据是否回送到本地回环接口
struct ip_mreq{
struct in_addr imn_multicastaddr;//多播组地址
struct in_addr imr_interface;//加入的接口的IP地址
}
例子:
int ttl=255;
setsockopt(s,IPPROTO_IP,IP_MULTICAST_TTL,&ttl,sizeof(ttl));//设置跳数
s-套接字描述符
PROTO_IP-选项所在的协议层
IP_MULTICAST_TTL-选项名
&ttl-设置的内存缓冲区
sizeof(ttl)-设置的内存缓冲区长度

struct in_addr in;
setsockopt(s,IPPROTO_IP,IP_MUTLICAST_IF,&in,sizeof(in));//设置组播接口

int yes=1;
setsockopt(s,IPPROTO_IP,IP_MULTICAST_LOOP,&yes,sizeof(yes));//设置数据回送到本地回环接口

struct ip_mreq addreq;
setsockopt(s,IPPROTO_IP,IP_ADD_MEMBERSHIP,&req,sizeof(req));//加入组播组

struct ip_mreq dropreq;
setsockopt(s,IPPROTO_IP,IP_DROP_MEMBERSHIP,&dropreq,sizeof(dropreq));//离开组播组

组播程序的设计流程:
(1)建立socket
(2)设置跳数TTL
(3)设置是否允许本地回环
(4)加入组播组
(5)发送数据
(6)接收数据
(7)离开多播组
(8)关闭套接字
**/

//服务器实现向多播组发送数据
#define MCAST_PORT 8888
#define MCAST_ADDR "224.0.0.88"
int main(int argc,char*argv[]){
int ret;
int s;
int i=1;
struct sockaddr_in Multi_addr;//多播地址
struct sockaddr_in client_addr;
s=socket(AF_INET,SOCK_DGRAM,0);//建立数据报套接字
if(s<0){
perror("socket error");
return -1;
}
Multi_addr.sin_family=AF_INET;
Multi_addr.sin_port=htons(MCAST_PORT);//多播端口
Multi_addr.sin_addr.s_addr=inet_addr(MCAST_ADDR);//多播地址
//向多播组发送数据
char buffer[1024];
for(;;){
memset(buffer,0,sizeof(buffer));
sprintf(buffer,"%d",i);
int size=sendto(s,buffer,strlen(buffer),0,(struct sockaddr*)&Multi_addr,sizeof(Multi_addr));
if(size<0){
perror("sendto error");
}
sleep(1);
i++;
memset(buffer,0,sizeof(buffer));
int len=sizeof(client_addr);
size=recvfrom(s,buffer,1024,0,(struct sockaddr*)&client_addr,&len);
write(1,buffer,size);
}
close(s);
}
