#include <stdio.h>
#include <math.h>

int main()
{
	int m,n;
	int n0,n1;
	scanf("%d",&n);

	while(n-->0)
	{
		n0=n1=0;
		scanf("%d",&m);
		while(m!=0)
		{
			if(m%2!=0)
				n1++;
			else
				n0++;
			m=m>>1;
		}
		printf("%d %d\n",n0,n1);
	}

	
	return 0;
}