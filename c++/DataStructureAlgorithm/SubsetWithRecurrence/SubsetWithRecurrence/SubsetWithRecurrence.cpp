// SubsetWithRecurrence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

#define N 20
int used[N];

void output(string str)
{
	for (int i = 0;i<N;i++)
	{
		if(used[i]==1)
		{
			cout << str[i] << " ";	
		}
	}
	cout << " * "<<endl;
}

void subset(string str,int length,int index)
{
	if (index>=length)
	{
		//cout << str << " " <<endl;
		output(str);
	} 
	else
	{
		used[index] = 1;
		subset(str,length,index+1);
		used[index] = 0;
		subset(str,length,index+1);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	string str;
	while (cin>>str)
	{
		subset(str,str.length(),0);
	}
	return 0;
}

