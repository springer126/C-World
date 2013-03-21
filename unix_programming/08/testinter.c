
#include "apue.h"
#include <sys/wait.h>

int main()
{
		pid_t pid;
		if((pid= fork())<0)
			err_sys("fork error\n");
		else if(pid ==0)
		{
			if(execl("/home/wh/cpp/unix_programming/08/testinterp","foo","kaka",(char*)0)<0)
				err_sys("execl error\n");
		}
		
		if(waitpid(pid,NULL,0)<0)
			err_sys("wait error!\n");
			
		exit(0);
}
