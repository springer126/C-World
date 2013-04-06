#include <stdio.h>



void sort(int* A,int low,int high)
{
	if(low>=high)
		return;
	else
	{
		int i=low,j=high;
		int pivot = A[i];

		while(i<j)
		{
			while(A[j]>=pivot && i<j)j--;
			A[i]=A[j];
			while(A[i]<=pivot && i<j)i++;
			A[j]=A[i];
		}

		A[j]=pivot;
		sort(A,low,j-1);
		sort(A,j+1,high);
	}
	
}

int main()
{
	int N;
	int K;
	int num[100000];
	int que[100];
	int i;
	while(scanf("%d",&N)!=EOF)
	{
		for(i=0;i<N;i++)
			scanf("%d",&num[i]);

		scanf("%d",&K);
		for(i=0;i<K;i++)
			scanf("%d",&que[i]);
		
		sort(num,0,N-1);

		for(i=0;i<K;i++)
			printf("%d\n",num[que[i]-1]);

	}
	return 0;
}
