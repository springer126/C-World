
#include "apue.h"
#include <fcntl.h>

extern void TELL_WAIT();
extern void TELL_CHILD(pid_t pid);
extern void TELL_PARENT(pid_t pid);
extern void WAIT_CHILD();
extern void WAIT_PARENT();


static int number = 0;
static char str[10];

void pr()
{
	printf("Pid = %d,Number = %d\n",getpid(),number);
}

int getNumber(const char* pathname)
{
	int fid;
	if((fid = open(pathname, O_RDONLY))<0)
			err_sys("open file error...\n");
	int n = read(fid,str,10);
	//printf("read %d bytes....\n",n);
	if(n<0)
		err_sys("read file error...\n");
	int number = atoi(str);
	if(number==0)
		err_sys("atoi error...\n");
	close(fid);
	return number;
}

void setNumber(const char* pathname,int number)
{
	int fid;
	if((fid = open(pathname, O_WRONLY))<0)
			err_sys("open file error...\n");
	sprintf(str,"%d",number);
	write(fid,str,strlen(str));
	close(fid);
}

int main()
{
	int fid;
	pid_t pid;
	if((fid = open("number.txt", O_WRONLY|O_CREAT|O_TRUNC))<0)
		err_sys("create file error...\n");
	
	sprintf(str,"%d",number);
	write(fid,str,strlen(str));
	close(fid);
	
	TELL_WAIT();
	
	if((pid = fork())<0)
		err_sys("fork error");
	else if(pid==0)
	{
		while((getNumber("number.txt")+1)<1000)
		{
			WAIT_PARENT();
			number  = getNumber("number.txt");
			setNumber("number.txt",number+1);
			printf("Pid = %d,Number = %d\n",getpid(),number+1);
			TELL_PARENT(getppid());
		}
	}
	else
	{
		while((getNumber("number.txt")+1)<1000)
		{
			number  = getNumber("number.txt");
			setNumber("number.txt",number+1);
			printf("Pid = %d,Number = %d\n",getpid(),number+1);
			TELL_CHILD(pid);
			WAIT_CHILD();
		}
		
		
	}
	
	
	close(fid);
	return 0;
}
