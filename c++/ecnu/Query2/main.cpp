#include "stdio.h"

int main(int argc, char* argv[])
{
	int m,n,i,temp;
	int a[100001];
	for(i=0;i<100001;i++)
		a[i]=0;
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&temp);
		a[temp]=1;
	}
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		if(a[temp]==1)printf("yes!\n");
		else printf("no!\n");
	}
	return 0;
 
}