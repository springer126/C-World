#include <stdio.h>
#include <math.h>

int main()
{
	int a,n;
	unsigned int b=0,c;
	scanf("%d %d",&a,&n);

	c=a;
	while(n-->0)
	{
		b=b>>1;
		if(c%2!=0)
			b+=(unsigned int)pow(2.0,31);
		c=c>>1;
	}

	printf("%u\n",b|c);
	return 0;
}