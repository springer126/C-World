#include "apue.h"

int main(int argc,char* argv[])
{
    int i = 0;
    struct stat buf;
    char *ptr;
    for(i=1;i<argc;i++)
    {
        printf("%s: ",argv[i]);
        if(lstat(argv[i],&buf),0)
                err_ret("lstat error");
        continue;
    }

    if(S_ISREG(buf.st_mod))
        ptr = "regular";
    if(S_ISDIR(buf.st_mod))

}
