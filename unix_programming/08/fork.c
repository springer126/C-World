
#include "apue.h"

int glob = 9;

int main()
{
	int var = 10;
	printf("before fork....\n");
	pid_t pid;
	if((pid=fork())<0)
		printf("fork error!\n");
	else if(pid==0)
	{
		glob++;
		var++;
	}
	else
	{
		sleep(2000000);
	}
	printf("pid = %d,ppid = %d,glob = %d,var = %d\n",getpid(),getppid(),glob,var);
	return 0;
}
