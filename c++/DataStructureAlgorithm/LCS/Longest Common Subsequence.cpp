// Longest Common Subsequence.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
using namespace std;

#define MAX 100
int c[MAX][MAX];
int flag[MAX][MAX];
int length;

int las(int* a,int len)
{
	if(len==1)
	{
		return a[0];
	}
	else
	{
		for(int i=len-1;i>0;i--)
		{
			if(a[i]>las(a,len-1))
			{
				cout << a[i]<<" ";
				return a[i];
			}
			else
				return las(a,len-1);
		}
	}
}

int lcs(int *a,int la,int *b,int lb)
{
	if(a==NULL || b==NULL || la>100 || lb>100 || la<1 || lb<1)
		return -1;

	int i=0,j=0;
	for(i=0;i<=la;i++)
		c[i][0] = 0;
	for(i=0;i<=lb;i++)
		c[0][i] = 0;

	for(i=1;i<=la;i++)
	{
		for(j=1;j<=lb;j++)
		{
			if(a[i-1]==b[j-1])
			{
				c[i][j] = c[i-1][j-1]+1;
				flag[i][j] = 0;
			}
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j] = c[i-1][j];
				flag[i][j] = 1;
			}
			else{
				c[i][j] = c[i][j-1];
				flag[i][j] = 2;
			}
		}
	}

	length = c[la][lb];
	return c[la][lb];
}

void print(int *a,int la,int lb)
{
	if(la==0 || lb==0)
		return;

	if(flag[la][lb]==0)
	{
		print(a,la-1,lb-1);
		cout << a[la-1] <<" ";
	}
	else if(flag[la][lb]==1)
	{
		print(a,la-1,lb);
	}
	else
	{
		print(a,la,lb-1);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = {1,2,3,4,5,3,5,6,7,0};
	int b[] = {2,3,5,3,7,8,0};
	cout << lcs(a,10,b,7)<<endl;

	for(int i=0;i<10;i++)
		cout << a[i] << " ";
	cout << endl;

	for(int i=0;i<7;i++)
		cout << b[i] << " ";
	cout << endl;

	print(a,10,7);
	cout <<endl;

	cout << "================================"<<endl;
	for(int i=0;i<11;i++)
	{
		for(int j=0;j<8;j++)
		{
			cout << c[i][j]<<" ";
		}
		cout << endl;
	}

	cout << "================================"<<endl;
	for(int i=0;i<11;i++)
	{
		for(int j=0;j<8;j++)
		{
			cout << flag[i][j]<<" ";
		}
		cout << endl;
	}

	cout << "========================" << endl;
	las(a,10);
	return 0;
}

