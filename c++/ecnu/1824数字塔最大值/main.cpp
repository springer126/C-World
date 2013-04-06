#include "iostream"
#include "cmath"
using namespace std;

int a[100][100];

int cal(int i,int j,int high)
{
	int m,n,temp;

	if(i==high-1)
	{
		temp=a[i][j]%10;
		return temp;
	}
	else
	{
		temp=a[i][j];
		m=(temp+cal(i+1,j,high))%10;
		n=(temp+cal(i+1,j+1,high))%10;
		
		if(m>n)
			return m;
		else
			return n;
	}
}

void init(int h)
{
	for(int i=0;i<h;i++)
		for(int j=0;j<=h;j++)
			a[i][j]=i*j;
}

int main()
{
	int C,N;
	int i,j;

	cin>>C;
	while(C--)
	{
		/*
		cin>>N;
		memset(a,-1,sizeof(a));
		for(i=0;i<N;i++)
			for(j=0;j<=i;j++)
			{
				cin>>a[i][j];
				a[i][j]%=10;
			}
		*/
		init(10);
		cout<<cal(0,0,N)<<endl;
	}

	return 0;
}