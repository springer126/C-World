#include "iostream"
using namespace std;

int a[10][10];
int b[10][10];
int c[10][10];

int T;
int n,k;
const int MOD=9973;

int tr()
{
	int sum=0;
	for(int i=0;i<n;i++)
		sum=(sum+c[i][i])%MOD;

	return sum;
}

void twice()
{
	int t;
	int i,j;
	memset(b,0,sizeof(b));
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			t=0;
			for(int k=0;k<n;k++)
				t=(t+a[i][k]*a[k][j])%MOD;
			b[i][j]=t;
		}

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=b[i][j];
}

void multi()
{
	int t;
	int i,j;
	memset(b,0,sizeof(b));
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			t=0;
			for(int k=0;k<n;k++)
				t=(t+a[i][k]*c[k][j])%MOD;
			b[i][j]=t;
		}

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			c[i][j]=b[i][j];
}

int main()
{
	
	int i,j;
	int ret;
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				cin>>a[i][j];
				if(i==i)
					c[i][j]=1;
				else
					c[i][j]=0;
			}
		
		ret=1;
		while(k)
		{
			if(k&1)
				multi();

			twice();
			k=k>>1;
		}

		cout<<tr()<<endl;

	}

	return 0;
}

