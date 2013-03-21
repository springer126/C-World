#include "apue.h"
#include <setjmp.h>
#include <time.h>
#include <errno.h>
static void sig_usr1(int signo);
static void sig_alarm(int signo);

static sigjmp_buf jmpbuf;
/*
 * typedef int __sig_atomic_t; 
 * sig_atomic_t int类型的变量通常是原子访问的，
 * 也可以认为 sig_atomic_t就是int类型的数据，
 * 因为对这些变量要求一条指令完成
 */
static volatile sig_atomic_t canjump;


static void pr_mask1(const char* str)
{
	sigset_t sigset;
	int error_save;
	
	error_save = errno;
	if(sigprocmask(0,NULL,&sigset)<0)
		err_sys("sigprocmask error....\n");
	
	printf("%s",str);
	if(sigismember(&sigset,SIGINT))printf(" SIGINT ");
	if(sigismember(&sigset,SIGQUIT))printf(" SIGQUIT ");
	if(sigismember(&sigset,SIGUSR1))printf(" SIGUSR1 ");
	if(sigismember(&sigset,SIGALRM))printf(" SIGALRM ");
	
	printf("\n");
	errno = error_save;
}

int main(void)
{	signal(SIGUSR1,sig_usr1);
	signal(SIGALRM,sig_alarm);
	
	pr_mask1("Starting main....\n");
	if(sigsetjmp(jmpbuf,1))
	{
		pr_mask1("ending main....\n");
		exit(0);
	}
	canjump = 1;
	for(;;)
		pause();
	return 0;
}

static void sig_usr1(int signo)
{
	time_t starttime;
	sigset_t sigset;
	sigset_t osigset;
	
	sigprocmask(0,NULL,&sigset);
	sigaddset(&sigset,signo);
	sigprocmask(SIG_SETMASK,&sigset,&osigset);
	
	if(canjump == 0)
		return;
	pr_mask1("Starting sig_usr1....");
	alarm(3);
	starttime = time(NULL);
	for(;;)
	{
		if(time(NULL)>starttime+5)
			break;
		
	}
	pr_mask1("Sig_usr1 FInished....");
	canjump = 0;
	siglongjmp(jmpbuf,1);
	
	sigprocmask(SIG_SETMASK,&osigset,&sigset);
}

static void sig_alarm(int signo)
{
	sigset_t sigset;
	sigset_t osigset;
	
	sigprocmask(0,NULL,&sigset);
	sigaddset(&sigset,signo);
	sigprocmask(SIG_SETMASK,&sigset,&osigset);
	
	pr_mask1("in sig_alarm....\n");
	//pr_mask1("in sig_alarm....\n");
	sigprocmask(SIG_SETMASK,&osigset,&sigset);
}
