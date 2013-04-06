#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 20000
bool is[MAX];
int prime[2262];

void deal(int N)
{
	int sq = (int)sqrt((double)N)+1;
	int i,j;
	memset(is,true,sizeof(is));
	is[1]=false;
	
	for(i=4;i<=N;i+=2)
		is[i]=false;

	for(i=3;i<sq;i+=2)
		if(is[i])
		{
			j=i+i;
			while(j<=N)
			{
				is[j]=false;
				j+=i;
			}
		}
}

int main()
{
	int T,a;
	int count=0;
	deal(MAX);

	for(int i=2;i<20000;i++)
		if(is[i])
			prime[count++]=i;

	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d",&a);
		for(int i=0;i<2262;i++)
		{
			count=0;
			while(a%prime[i]==0)
			{
				a=a/prime[i];
				count++;
			}

			if(count!=0)
				printf("(%d,%d)",prime[i],count);
		}
		printf("\n");

	}

	return 0;
}