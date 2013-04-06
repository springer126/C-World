#include <stdio.h>              
        
int main()
{
    int a,n,k;
    while (scanf("%d%d%d",&a,&n,&k) != EOF)
	{
        int t = 1;
        if (!n)
            t %= k;
        while (n)
		{
            if (n&1)
                t = (t*a)%k;
            a = (a%k)*(a%k);
            a %= k;
            n >>= 1;
        }
        printf("%d\n",t);
    }
    return 0;
	
}