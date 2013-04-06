#include <iostream>
using namespace std;

int a[100];
int count;

//the k-th largest number from 1 to m
void comb(int m,int k)
{
	if(k < 1 && m < k)
	{
		cout << "Invalid Argument."<< endl;
		return;
	}

	for (int i=m;i>=k;i--)
	{
		a[k]=i;
		if(k>1)
		{
			comb(i-1,k-1);
		}
		else
		{
			count++;
			for(int j=a[0];j>0;j--)
			{
				cout<<" " <<a[j];
			}
			cout << endl;
		}
		
	}
}

int main()
{
	
	int m,k;
	
	while (cin>>m>>k)
	{
		count = 0;
		a[0]=k;
		comb(m,k);
		cout << "Sum :" << count <<endl;
	}
	return 0;
}
