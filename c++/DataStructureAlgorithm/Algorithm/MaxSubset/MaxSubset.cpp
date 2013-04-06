// MaxSubset.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int MaxSubset(int *a,int length)
{
	if(length<=0)
		return 0;
	int sum = a[0];
	int b = 0;
	int beg = 0,end = 0;
	for (int i=0;i<length;i++)
	{
		if (b<=0)
		{
			b = a[i];
			beg = i;
		}
		else
		{
			b += a[i];
		}
		if(b>sum)
		{
			sum = b;
			end = i;
		}
	}
	printf("[%d,%d] = %d",beg+1,end+1,sum);
	return sum;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = {1,-2,3,10,-4,7,-5,2,2,-5};
	MaxSubset(a,10);
	return 0;
}

