/*
 *openlog， syslog， closelog::系统日志写入接口
 *
 */

#include "apue.h"
#include <syslog.h>


int main(int argc,char* argv[])
{
	openlog("WENHUI",LOG_CONS|LOG_PID,0);
	syslog(LOG_DEBUG,"THIS IS TEST MESSAGE LOG BY '%s'\n",argv[0]);	
	closelog();

	return 0;
}
