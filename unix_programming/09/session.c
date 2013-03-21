
#include "apue.h"

int main()
{
	printf("before fork....\n");
	pid_t pid;
	if((pid=fork())<0)
		printf("fork error!\n");
	else if(pid==0)
	{
		pid = setsid();
		//getchar();
		//_exit(0);
	}
	else
		sleep(1);
		
	printf("pid = %d,ppid = %d,sid = %d\n",getpid(),getppid(),getsid(0));
	return 0;
}
