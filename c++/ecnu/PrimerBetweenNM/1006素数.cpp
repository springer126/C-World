#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1000000
int count[MAX];
bool is[MAX];

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
	int n,m;
	int i,j,temp;

	deal(MAX);
	memset(count,0,sizeof(count));
	
	for(i=2;i<=MAX;i++)
	{
		j=is[i]?1:0;
		count[i]=count[i-1]+j;
	}

	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(n>m)
		{
			temp=n;
			n=m;
			m=temp;
		}
	
		printf("%ld\n",count[m]-count[n-1]);
	}
	return 0;
}