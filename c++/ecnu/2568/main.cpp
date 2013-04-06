#include <stdio.h>

int getDigit(long int a,long int b)
{
	int d=1;
	long int sum = a+b;
	while(sum/10!=0)
	{
		d++;
		sum/=10;
	}

	return d;
}

int main()
{
	int N;
	long int a,b;

	scanf("%d",&N);
	while(N-->0)
	{
		scanf("%ld %ld",&a,&b);
		printf("%d\n",getDigit(a,b));
	}
	return 0;
}