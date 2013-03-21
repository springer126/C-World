
#include "apue.h"

int glob = 9;

void f1()
{
	pid_t pid;
	if((pid=vfork())<0)
		printf("fork error!\n");
}

void f2()
{
	int i;
	char buf[1000];
	for(i =0;i<1000;i++)
	{
		buf[i] = 0;
	}
}

int main()
{
	int var = 10;
	printf("before vfork....\n");
	pid_t pid;
	if((pid=vfork())<0)
		printf("fork error!\n");
	else if(pid==0)
	{
		glob++;
		var++;
		_exit(0);
	}
	
	printf("pid = %d,ppid = %d,glob = %d,var = %d\n",getpid(),getppid(),glob,var);
	printf("=======================================\n	");
	
	f1();
	f2();
	return 0;
}
