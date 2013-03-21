#include "apue.h"
#include <pwd.h>
#include <time.h>

void sig_alarm(int sig)
{
	struct passwd *pwd;
	signal(SIGALRM,sig_alarm);
	if(sig == SIGALRM)
	{
		if((pwd = getpwnam("wh2"))==NULL)
		{
			err_sys("error\n");
		}
	}
	alarm(1);
}

int main()
{
	struct passwd *pwd;
	signal(SIGALRM,sig_alarm);
	alarm(1);
	time_t t;
	struct tm *ts;
	char *st;
	t = time(&t);
	ts = localtime(&t);
	st = asctime(ts);
	for(;;)
	{
		if((pwd = getpwnam("wh"))==NULL)
			err_sys("error!\n");
		if(strcmp(pwd->pw_name,"wh")!=0)
		{
			sleep(1);
			printf("return value corupted ! name = %s \n",pwd->pw_name);
		}
		else
			printf("date = %s,name = %s \n",st,pwd->pw_name);
			
		
	}
}
