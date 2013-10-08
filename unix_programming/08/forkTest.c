#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


int num = 0;

int main()
{
    int i;
    for(i=0;i<5;i++)
    {
        if(fork()==0)
             continue;
    }
    
    printf("%d\n",num);
    getchar();
} 
