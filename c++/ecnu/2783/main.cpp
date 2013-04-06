#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 3000
//int a[N];
//int b[N];

int main()
{
	/*
	int t,n,i,j,flag;
	scanf("%d",&t);

	for(i=0;i<t;i++)
	{
		memset(b,0,sizeof(b));
		scanf("%d",&n);
		for(j=0;j<n;j++)
			scanf("%d",&a[j]);

		
		for(j=0;j<n-1;j++)
			b[int(fabs((double)(a[j]-a[j+1])))]=1;
	
		flag = 0;
		for(j=1;j<n;j++)
		{
			if(b[j]!=1)
			{
				flag=1;
				break;
			}
		}

		if(flag)
			printf("Not jolly\n");
		else
			printf("Jolly\n");
	}

	return 0;
	*/

	int t,n,i,j,a[3000],b[3000],flag;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		for(j=0;j<3000;j++)
			b[j]=0;
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[j]);
			b[a[j]]=1;
		}
		flag=1;
		for(j=0;j<n;j++)
		{
			if(b[int(fabs(a[j]-a[j+1]))]!=1)
			{
				printf("not jolly\n");
				flag=0;
				break;
			}		
		}
		if(flag)
			printf("Jolly\n");
	}
	return 0;

}