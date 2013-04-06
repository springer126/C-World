#include <stdio.h>

int gcd(int m,int n)
{
	int temp;
	while(m%n!=0)
	{
		temp=m;
		m=n;
		n=temp%n;
	}
	return n;
}

int main()
{
	int m,n;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		printf("%d\n",gcd(m,n));
	}

	return 0;
}