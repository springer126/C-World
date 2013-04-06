
#include <iostream>
using namespace std;

char a[4][4];
char b[4][4];
int n;


bool check(int x,int y)
{
	int i;

	i=y-1;
	while(i>=0 && a[x][i]=='.')i--;
	if(i>=0 && a[x][i]=='A')
		return false;
	
	i=y+1;
	while(i<n && a[x][i]=='.')i++;
	if(i<n && a[x][i]=='A')
		return false;

	i=x-1;
	while(i>=0 && a[i][y]=='.')i--;
	if(i>=0 && a[i][y]=='A')
		return false;

	i=x+1;
	while(i<n && a[i][y]=='.')i++;
	if(i<n && a[i][y]=='A')
		return false;

	return true;
}

int getNumOfBlock()
{
	int num = 0;			
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
				if(a[i][j]=='A')num++;
	return num;
}

void copy()
{
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			b[i][j] = a[i][j];
		}
}

int main()
{
	int count;
	int temp;

	cin>>n;
	while(n!=0)
	{
		int i,j;count = 0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				a[i][j] = 0;
		
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				cin>>a[i][j];
		
		for(i = 0;i<n;i++)
			for(j=0;j<n;j++)
			{	 
				if(check(i,j) && a[i][j]=='.')
						a[i][j]='A';
				
				copy();
				b[i][j]='.';
			}

			
		temp = getNumOfBlock();
	
		cout<<count<<endl;	
	
		
		cin>>n;
	}

	return 0;
}

 
