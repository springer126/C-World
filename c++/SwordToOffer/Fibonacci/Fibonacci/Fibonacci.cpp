// Fibonacci.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//一只青蛙一次可以跳上一级或者两级，该青蛙跳上n级的跳法
//Fibonacci数列 f(n) = f(n-1)+f(n-2)
int ways(int n)
{
	if(n==1 || n==2)
		return 1;
	else
	{
		return ways(n-1)+ways(n-2);
	}
}

int aways(int n)
{
	if(n==1 || n==2)
		return 1;
	else
	{
		int f1 = 1;
		int f2 = 1;
		int f3;
		for (int i=3;i<=n;i++)
		{
			f3 = f1+f2;
			f1 = f2;
			f2 = f3;
		}
		return f3;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	printf("%d\n",aways(10));
	return 0;
}

