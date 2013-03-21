#include "apue.h"
#include <signal.h>
#include <setjmp.h>

static jmp_buf env_alarm;

void sig_alrm(int signo)
{
	if(signo==SIGALRM)
	{
		longjmp(env_alarm,1);
	}
}

int main(void)
{
	char buf[MAXLINE];
	int n;
	
	signal(SIGALRM,sig_alrm);
	alarm(10);
	if(setjmp(env_alarm)==0)
	{
		if((n = read(STDIN_FILENO,buf,MAXLINE))<0)
		{
			err_sys("read error!\n");
		}
		alarm(0);
		write(STDOUT_FILENO,buf,n);
	}else
	{
		printf("Time elapsed 10 seconds!\n");
	}
	exit(0);
}
