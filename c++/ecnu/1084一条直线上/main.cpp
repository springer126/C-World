#include "iostream"
#include "cstdio"
#include "utility"
#include "algorithm"
using namespace std;

pair<int,int> cod[700];
pair<int,int> temp[700];
int n;

int gcd(int x,int y)
{
	if(y==0)
		return x;
	else
		return gcd(y,x%y);
}

bool com(pair<int,int> &a,pair<int,int> &b)
{
	if(a.first<b.first)return true;
	if(a.first==b.first && a.second<b.second)return true;
	else
		return false;
}

int deal()
{
	int i,j,k;
	int ans;
	int now;
	int max=2;

	memset(cod,0,sizeof(cod));
	memset(temp,0,sizeof(temp));

	for(i=0;i<n;i++)
		scanf("%d %d",&cod[i].first,&cod[i].second);

	for(i=0;i<n-1;i++)
	{	
		now=0;
		for(j=i+1;j<n;j++)
		{
			temp[now].first=cod[j].first-cod[i].first;
			temp[now].second=cod[j].second-cod[i].second;
			k=gcd(temp[now].first,temp[now].second);
			temp[now].first/=k;
			temp[now].second/=k;
			now++;
		}
		
		sort(temp,temp+now,com);

		while(j<now-1)
		{
			ans=2;
			while(temp[j+1].first==temp[j].first && temp[j+1].second==temp[j].second)
			{
				ans++;
				j++;
			}

			if(max<ans)
				max=ans;
			j++;
		}
		
			
	}

	return max;
}

int main()
{
	while(true)
	{
		cin>>n;
		if(n==0)break;
		cout<<deal()<<endl;
	}

	return 0;
}