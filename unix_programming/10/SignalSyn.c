
#include "apue.h"

/*
 * 利用信号机制实现父子进程之间的同步操作
 * 子进程WAIT直至父进程给子进程发送SIGUSR1信号
 * 父进程WAIT直至子进程给父进程发送SIGUSR2信号
 * 
 * 
 */

static volatile sig_atomic_t signal_flag;
static sigset_t newmask,oldmask,zeromask;

void sig_usr(int sig)
{
	signal_flag = 1;
}

void TELL_WAIT()
{
	signal(SIGUSR1,sig_usr);
	signal(SIGUSR2,sig_usr);
	
	sigemptyset(&newmask);
	sigemptyset(&zeromask);
	sigaddset(&newmask,SIGUSR1);
	sigaddset(&newmask,SIGUSR2);
	if(sigprocmask(SIG_BLOCK,&newmask,&oldmask)<0)
		err_sys("sigprocmask error!\n");
}

void TELL_CHILD(pid_t pid)
{
	kill(pid,SIGUSR1);
}

void WAIT_PARENT()
{
	while(signal_flag==0)
		sigsuspend(&zeromask);
	signal_flag = 0;
	
	if(sigprocmask(SIG_SETMASK,&oldmask,NULL)<0)
		err_sys("SIG_SETMASK ERROR!\n");
}

void TELL_PARENT(pid_t pid)
{
	kill(pid,SIGUSR2);
}

void WAIT_CHILD()
{
	while(signal_flag==0)
		sigsuspend(&zeromask);
	signal_flag = 0;
	
	if(sigprocmask(SIG_SETMASK,&oldmask,NULL)<0)
		err_sys("SIG_SETMASK ERROR!\n");
}
