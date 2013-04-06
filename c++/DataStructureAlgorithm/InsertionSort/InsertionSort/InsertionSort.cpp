// InsertionSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>

void InsertionSort(int a[],int n)
{
	if(n==0)
		return;
	int i,j;
	for (i=0;i<n;i++)
	{
		int pos = a[i];
		for (j=i-1;j>=0 && a[j]>pos;j--)
		{
			a[j+1] = a[j];
		}
		a[j+1] = pos;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[10000];
	clock_t start,finish;
	for (int i=0;i<10000;i++)
	{
		a[i] = 10000-i;
	}
	start = clock();
	std::cout << start <<std::endl;
	InsertionSort(a,10000);
	finish = clock();
	std::cout << finish <<std::endl;
	std::cout << (double)(finish-start)/CLOCKS_PER_SEC << std::endl;
	return 0;
}

