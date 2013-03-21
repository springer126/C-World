#include <pwd.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>


//#define struct passwd PASSWD;

struct passwd  *getpwnam1(const char *name)
{
		struct passwd  *ptr;
		setpwent();
		while((ptr=getpwent())!=NULL)
				if(strcmp(ptr->pw_name,name)==0)
						break;
		
		endpwent();
		return ptr;
}

int main()
{
		char name[20];
		struct passwd  *ptr;
		while(gets(name)!=NULL)
		{
				ptr = getpwnam1(name);
				if(ptr!=NULL)
				{
						printf("name = %s,passwd = %s,uid = %d,gid = %d\n",ptr->pw_name,ptr->pw_passwd,ptr->pw_uid,ptr->pw_gid);
				}
		}
}
