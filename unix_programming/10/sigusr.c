
#include "apue.h"

int sig_int_flag ;

void sig_usr(int);

void sig_int(int sig)
{
	signal(SIGINT,sig_int);
	if(sig == SIGINT)
	{
		printf("receive SIGINT,sig_int_flag = %d\n",sig_int_flag);
	}
	sig_int_flag = 1;
}

int main()
{
	/*
	if(signal(SIGUSR1,sig_usr)==SIG_ERR)
		err_sys("can't receive SIGUSR1\n");
	if(signal(SIGUSR2,sig_usr)==SIG_ERR)
		err_sys("can't receive SIGUSR2\n");
	for(;;)
		pause();
	*/
		
	/*
	signal(SIGINT,sig_int);
	sleep(10);
	*/
	
	signal(SIGINT,sig_int);
	//go to sleep ,for waiting for signal
	while(sig_int_flag==0)
	{
		pause();
	}
	
	
	for(;;)
	{
		sig_int_flag = sig_int_flag%100==0?1:sig_int_flag;
	}
	
	return 0;	
}


void sig_usr(int sig)
{
	if(sig==SIGUSR1)
		printf("catch a signal:SIGUSR1\n");
	else if(sig==SIGUSR2)
		printf("catch a signal:SIGUSR2\n");
	else
		err_dump("received signal %d \n",sig);
}
