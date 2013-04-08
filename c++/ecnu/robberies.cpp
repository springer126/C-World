#include <iostream>
#include <algorithm>
using namespace std;

struct Bank
{
	int mj;
	float pj;
	Bank(int m = 0,float p = 0.0):mj(m),pj(p){}
	bool operator <(const Bank &bank) const
	{
		return pj < bank.pj;
	}
};


int t,n;
float p;
struct Bank banks[100];
int profit[100];

int cal()
{
	std::sort(banks,banks+n);
}

int main()
{
	int i,j,k;
	if(cin>>t)
	{
		for(i=0;i<t;i++)
		{
			if(cin >> p >> n)
			{
				for(j=0;j<n;j++)
				{
					cin >> banks[j].mj >> banks[j].pj;
					profit[j] = banks[j].mj;
				}
			}
			cout << cal() << endl;
		}
	}
}
