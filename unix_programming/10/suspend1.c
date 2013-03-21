#include "apue.h"

static void	sig_int(int);

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


int
main(void)
{
	sigset_t	newmask, oldmask, waitmask;

	pr_mask1("program start: ");

	if (signal(SIGINT, sig_int) == SIG_ERR)
		err_sys("signal(SIGINT) error");
	sigemptyset(&waitmask);
	sigaddset(&waitmask, SIGUSR1);
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGINT);

	/*
	 * Block SIGINT and save current signal mask.
	 */
	if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
		err_sys("SIG_BLOCK error");

	/*
	 * Critical region of code.
	 */
	pr_mask1("in critical region: ");

	/*
	 * Pause, allowing all signals except SIGUSR1.
	 */
	if (sigsuspend(&waitmask) != -1)
		err_sys("sigsuspend error");

	pr_mask1("after return from sigsuspend: ");

	/*
	 * Reset signal mask which unblocks SIGINT.
	 */
	if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		err_sys("SIG_SETMASK error");

	/*
	 * And continue processing ...
	 */
	pr_mask1("program exit: ");

	exit(0);
}

static void
sig_int(int signo)
{
	pr_mask1("\nin sig_int: ");
}
