#include "apue.h"
#include <time.h>

#include <signal.h>
#include <setjmp.h>

static jmp_buf env_alrm;

void sig_alarm(int sig)
{
	time_t t;
	struct tm *tt;
	alarm(1); 
	signal(SIGALRM,sig_alarm);
	if(sig==SIGALRM)
	{
		t = time(&t);
		tt = localtime(&t);
		printf("%d:%d:%d\n",tt->tm_hour,tt->tm_min,tt->tm_sec);
	}
}

static void sig_alrm(int signo)
{
	longjmp(env_alrm,1);
}

static int sleep2(int nseconds)
{
	time_t t;
	t = time(&t);
	printf("Sleep2 Start : %ld\n",t);
	if(signal(SIGALRM,sig_alrm)==SIG_ERR)
		return nseconds;
	if(setjmp(env_alrm)==0)
	{
		alarm(nseconds);
		pause();
	}
	
	t = time(&t);
	printf("Sleep2 Finished : %ld\n",t);
	return alarm(0);
}

static void sig_int(int signo)
{
	time_t t;
	t = time(&t);
	printf("Sig_int Start : %ld\n",t);
	//printf("sig_int starting...\n");
	int i,j;
	volatile int k;
	if(signo==SIGINT)
	{
		for(i=0;i<40000;i++)
			for(j=0;j<40000;j++)
				k = i*j;
		
		//printf("sig_int finished...\n");
	}
	
	t = time(&t);
	printf("Sig_int Finished : %ld\n",t);
}

int main(void)
{
	/*
	signal(SIGALRM,sig_alarm);
	alarm(1);
	//pause();
	
	for(;;)
	{
		pause();
	}
	*/
	
	int sleept;
	signal(SIGINT,sig_int);
	sleept = sleep2(10);
	
	printf("sleep2 return : %d\n",sleept);
	return 0;
}
