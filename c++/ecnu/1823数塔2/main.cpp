#include "iostream"
#include "cmath"
using namespace std;

int a[100][100];
int t[100][100];

int cal(int low,int high)
{
	int max;
	int i,j;

	if(high==low)
	{
		max=t[high][0];
		for(i=0;i<=high;i++)
		{
			if(max<t[high][i])
				max=t[high][i];
		}

		return max;
	}
	else
	{
		for(i=high;i>low;i--)
			for(j=0;j<=i;j++)
			{
				max=t[i][j]>t[i][j+1]?t[i][j]:t[i][j+1];
				t[i-1][j]+=max;
			}
		
		max=t[low][0];
		for(i=0;i<=low;i++)
		{
			if(max<t[low][i])
				max=t[low][i];
		}

		return max;

	}
}

int main()
{
	int C,N;
	int i,j,max;

	cin>>C;
	while(C--)
	{
	
		cin>>N;
		for(i=0;i<N;i++)
			for(j=0;j<=i;j++)
				cin>>a[i][j];
		
		if(N==1)
			cout<<a[0][0]<<endl;
		else if(N==2)
			cout<<cal(0,1)<<endl;
		else
		{
			memcpy(t,a,sizeof(a));
			max=cal(0,0)+cal(1,N-1);
			for(i=1;i<N-1;i++)
			{
				memcpy(t,a,sizeof(a));
				j=cal(0,i)+cal(i+1,N-1);
				if(max<j)
					max=j;
			}
			cout<<max<<endl;
		}

	}

	return 0;
}