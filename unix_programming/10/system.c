#include "apue.h"
void sig_int(int sig)
{
	printf("caught SIGINT.....\n");
}

void sig_child(int sig)
{
	printf("caught SIGCHILD.....\n");
}

int main()
{
	signal(SIGINT,sig_int);
	signal(SIGCHLD,sig_child);
	if(system("/usr/bin/vim")<0)
		err_sys("system error\n");
	exit(0);
}
