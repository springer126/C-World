#include "apue.h"
#include <sys/wait.h>

int main()
{
	FILE *fpin;
	char line[MAXLINE];
	//popen(const char* cmd,const char* type)
	//如果type为"r"，fp为读打开，从管道中读
	if((fpin = popen("/home/wenhui/cpp/unix_programming/15.IPC/myfunc","r"))==NULL)
		err_sys("popen error");

	for(;;)
	{
		fputs("prompt > ",stdout);
		fflush(stdout);
		if(fgets(line,MAXLINE,fpin)==NULL)
			break;
		if(fputs(line,stdout)==EOF)
			err_sys("fputs error to pipe");
	}
	
	if(pclose(fpin)==-1)
		err_sys("pclose error");

	putchar('\n');
	exit(0);
}
