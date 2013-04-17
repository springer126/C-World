#include <iostream>
using namespace std;

char city[5][5];

int n;
int wx[5],wy[5];
int maxCount;

void search(int i,int j,int count)
{
	if(j>n)
		maxCount = maxCount>count?maxCount:count;
	else
	{
		if(i>n)
			search(1,j+1,count);
		else
		{
			if(city[i][j]=='X')
			{
				wx[i] = wy[j] = 0;
			}
			else if(wx[i]==0 && wy[j]==0)
			{
				wx[i] = wy[j] = 1;
				search(i+1,j,count+1);
				wx[i] = wy[j] = 0;
			}
			search(i+1,j,count);
		}
	}
}

int main()
{
	int i,j,k;
	while(cin>>n && n!=0)
	{
		for(i=1;i<n+1;i++)
		{
			for(j=1;j<n+1;j++)
				cin>>city[i][j];
			wx[i] = wy[i] = 0;
		}
		maxCount = 0;
		search(1,1,0);
		cout << maxCount << endl;


	}	
}
