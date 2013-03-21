#include <unistd.h>
#include "apue.h"

int main()
{
	uid_t euid = 0;
	gid_t egid = 0;
	
	if(!seteuid(euid))
		printf("setuid successfully!\n");
	else
		printf("seteuid error!\n");
	setegid(egid);
	printf("HOME = %s\nPATH = %s\nTZ = %s\n",getenv("HOME"),getenv("PATH"),getenv("TZ"));
	printf("PID = %d,PPID = %d,UID = %d,EUID = %d \n",getpid(),getppid(),getuid(),geteuid());
	
	
	int i = 3;
	pid_t pid;
	
	while(i>0)
	{
		i--;
		if((pid = fork()) > 0)
		{
			printf("parent process-");
			sleep(2);
		}
		else if(pid ==0)
		{
			printf("child process-");
		}
		else
			printf("error!\n");
			
		printf("PID = %d,PPID = %d,i = %d\n",getpid(),getppid(),i);
	}
	
	return 0;
}
