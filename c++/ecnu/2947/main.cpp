#include "iostream"
#include "string"
using namespace std;

#define N 1000
#define MAX 51
int A[MAX][N];
int s[N];

void sort(string str[],int low, int high)
{
	if(low>=high)
		return;
	else
	{
		int i=low,j=high;
		string pivot = str[i];

		while(i<j)
		{
			while(str[j]>=pivot && i<j)j--;
			str[i]=str[j];
			while(str[i]<=pivot && i<j)i++;
			str[j]=str[i];
		}

		s[j]=low;
		str[j]=pivot;
		sort(str,low,j-1);
		sort(str,j+1,high);
	}
}

int main()
{
	int T,line,temp;
	int i,j;
	char buffer[10];
	string t;
	string S[N];


	cin>>T;
	while(T--)
	{
		memset(A,-1,sizeof(A));
		memset(S,-1,sizeof(S));
		
		
		cin>>line;
		for(i=0;i<line;i++)
		{
			j=0;
			cin>>temp;
			S[i].empty();
			while(temp!=-1)
			{
				A[j][i]=temp;
				memset(buffer,0,10);
				t=itoa(A[j][i],buffer,10);
				S[i]+=t;
				j++;
				cin>>temp;
			}
		}
		
		sort(S,0,line-1);
		
		for(i=0;i<line;i++)
		{
			j=s[i];
			for(int k=0;k<MAX && A[j][k]!=-1;k++)
				cout<<A[j][k]<<" ";
			cout<<endl;
		}
	}

	return 0;
}

