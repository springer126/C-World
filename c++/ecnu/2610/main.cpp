#include <stdio.h>
#include <math.h>

int main()
{
	int T,M,K;
	int t[1000];
	int sum;
	scanf("%d",&T);
	while(T-->0)
	{
		sum=0;
		scanf("%d %d",&M,&K);
		if(M>=K)
		{
			for(int i=0;i<M;i++)
			{
				scanf("%d",&t[i]);
				if(i<K)
					sum+=t[i];
			}
		}

		printf("%d\n",sum);
	}
	
	return 0;
}