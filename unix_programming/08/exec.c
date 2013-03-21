
#include "apue.h"
#include <sys/wait.h>

char *env_init[] = {"USER=wh","PATH=/home/wh/cpp/unix_programming/08",NULL};

int main()
{
	pid_t pid;
	if((pid=fork())<0)
		err_sys("fork error!\n");
	else if(pid==0)
	{
		if(execle("/home/wh/cpp/unix_programming/08/echo","wenhui","kaka",(char*)0,env_init)<0)
			err_sys("execle error!\n");
	}	
	
	
	if(waitpid(pid,NULL,0)<0)
		err_sys("wait error!\n");
	
	sleep(2);
	
	if((pid=fork())<0)
		err_sys("fork error!\n");	
	else if(pid==0)
	{
		if(execlp("echo","ubuntu","meiling",(char*)0)<0)
			err_sys("execle error!\n");
	}	
	
	
	printf("pid = %d,ppid = %d\n",getpid(),getppid());
	return 0;
}
