
/*
#include <stdio.h>
#include <math.h>

int N;
char s[32];
int addr[4];


int main()
{
	int i,j,k;
	int temp;

	scanf("%d",&N);

	for(i=0;i<N;i++)
	{
		k=0;
		scanf("%s",s);
		for(j=0;j<32;j++)
		{
			if(j%8==0)
				temp=0;
			temp+=(int)(pow(2,7-j%8)*(s[j]-'0'));

			if(j%8==7)
			{
				addr[k]=temp;
				k++;
			}	
		}

		printf("%d.%d.%d.%d\n",addr[0],addr[1],addr[2],addr[3]);
	}

	return 0;
}

*/