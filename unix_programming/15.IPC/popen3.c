#include "apue.h"
#include <sys/wait.h>

int main()
{
	FILE *fpin;
	char line[MAXLINE];

	if(chdir("/")<0)
		err_quit("can not change to directory");

	//popen(const char* cmd,const char* type)
	//如果type为"r"，fp为读打开，从管道中读
	if((fpin = popen("/bin/ls -al","r"))==NULL)
		err_sys("popen error");

	while(fgets(line,MAXLINE,fpin)!=NULL)
	{

		if(fputs(line,stdout)==EOF)
			err_sys("fputs error to pipe");
	}
	
	if(pclose(fpin)==-1)
		err_sys("pclose error");

	exit(0);
}
