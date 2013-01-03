#include "apue.h"

int main()
{
    int c;
    while(c = getc(stdin)!=EOF)
    {
        if(putc(c,stdout)==EOF)
        {
           putc(c,stdout);
	   err_sys("output error");
        }
	putc(c,stdout);
    }
    if(ferror(stdin))
        err_sys("input error");
    return 0;
}
