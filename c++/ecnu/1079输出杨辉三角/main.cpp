#include "iostream"
using namespace std;

int a[30][30];

void output(int height)
{
	int i,j;
	memset(a,0,sizeof(a));
	a[0][0]=1;
	for(i=1;i<height;i++)
		for(j=0;j<=i;j++)
		{
			if(j==0 || j==i)
				a[i][j]=1;
			else
				a[i][j]=a[i-1][j-1]+a[i-1][j];
		}

	for(i=0;i<height;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(j==i)
				cout<<a[i][j]<<endl;
			else
				cout<<a[i][j]<<" ";
		}
	}

	cout<<endl;
}

int main()
{
	int n;
	cin>>n;
	while(n!=0)
	{
		output(n);
		cin>>n;
	}
	return 0;
}