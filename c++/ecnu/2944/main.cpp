#include "iostream"
#include "string"
using namespace std;

int main()
{
	int T,n;
	int i,j,k;
	int count;
	cin>>T;
	while(T--)
	{
		count=0;
		cin>>n;
		for(i=0;i<=n/4;i++)
			for(j=0;j<=(n-4*i)/3;j++)
				for(k=0;k<=(n-4*i-3*j)/2;k++)
					if(4*i+3*j+2*k<=n)
						count++;

		cout<<count<<endl;
	}

	return 0;
}