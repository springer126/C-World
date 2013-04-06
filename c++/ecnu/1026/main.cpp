#include <stdio.h>
#include <math.h>
#define G 9.8

float time(float height)
{
	return (float)sqrt(height*2/G);
}

int main()
{
	int i;
	double height;

	while(scanf("%d",&i)!=EOF)
	{
		if(i!=0)
		{
			if(i<=3)
				height = (i-1)*5+1.75;
			else
			{
				height = 11.75+(i-3)*3;
			}
			printf("%0.3f\n",time(height));
		}
		else
			break;
	}

	return 0;
}