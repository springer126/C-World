#include "apue.h"
#include <dirent.h>

int main(int argc,char *argv[])
{
    DIR *dp;
    struct dirent *dirp;
    if(argc !=2)
	err_quit("ls directory name");
    if((dp = opendir(argv[1]))==NULL)
        err_sys("Cannnot open %S",argv[1]);
    while((dirp = readdir(dp))!=NULL)
        printf("%s\n",dirp->d_name);
    closedir(dp);
    return 0;
}
