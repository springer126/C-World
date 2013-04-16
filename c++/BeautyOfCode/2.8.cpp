#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;

int solve(int *id,int N)
{
	int nTimes = 0;
	int i;
	int candidate = -1;
	for(i=0;i<N;i++)
	{
		if(nTimes==0)
		{
			candidate = id[i];
			nTimes = 1;
		}
		else
		{
			if(id[i]==candidate)
				nTimes++;
			else
				nTimes--;
		}
	}
	return candidate;
}

int* gen(int len)
{
	srand(time(NULL));
	int rd = rand()%100;
	cout << rd << endl;
	int *arr = (int *)malloc(sizeof(int)*len);
	memset(arr,0,len);
	
	for(int i=0;i<len/2+1;i++)
		arr[i] = rd;
	
	for(int i=0;i<len;i++)
	{
		if(arr[i]==0)
			arr[i] = rand()%100;
	}
	
	for(int i=0;i<len;i++)
	{
		int m = rand()%len;
		int n = rand()%len;
		int temp = arr[m];
		arr[m] = arr[n];
		arr[n] = temp;
	}
	
	
	return arr;
}


int main()
{
	//int a[10] = {42,54,1,54,54,54,54,82,87,54};
	int *arr = gen(100);
	cout << solve(arr,100) << endl;
	for(int i=0;i<100;i++)
		cout << arr[i] << " ";
	cout << endl;
	free(arr);
}
