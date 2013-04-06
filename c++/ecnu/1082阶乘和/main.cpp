#include "iostream"
using namespace std;

int N[10];

void init()
{
	int sum=1;
	N[0]=1;
	for(int i=1;i<10;i++)
	{
		N[i]=i*N[i-1];
	}
}

bool judge(int n)
{
	if(n==0)
		return false;
	else
	{
		int i=9;
		while(i>=0 && n!=0)
		{
			while(n<N[i])
				i--;
			n=n-N[i];
			i--;
		}

		if(n==0)
			return true;
		else
			return false;
	}
}

int main()
{
	int n;
	init();
	cin>>n;
	while(n>=0)
	{
		if(judge(n))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		cin>>n;
	}
	return 0;
}