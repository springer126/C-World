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
	int N;
	int m,n;
	int gc;

	printf("%d",sizeof(int));
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d %d",&m,&n);
		gc=gcd(m,n);
		printf("%d %d\n",gc,m*n/gc);

	}

	return 0;
}