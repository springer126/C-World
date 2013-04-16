//1-N中所有1的个数
#include <iostream>
#include <ctime>
#include <cstdio>
using namespace std;

int count1(unsigned int n)
{
	int count = 0;
	while(n!=0)
	{
		count+=(n%10==1)?1:0;
		n = n/10;
	}
	return count;
}

int f(unsigned int n)
{
	int sum = 0;
	for(unsigned int i = 1;i<=n;i++)
		sum += count1(i);
	return sum;
}


int count2(unsigned int n)
{
	int sum = 0;
	int iFactor = 1;
	int iLower;
	int iHigher;
	int iCur;
	while(n/iFactor!=0)
	{
		iLower = n%(iFactor);
		iHigher = n/(iFactor*10);
		iCur = n%(iFactor*10)/iFactor;
		
		switch(iCur)
		{
		case 0:
			sum+=iHigher*iFactor;
			break;
		case 1:
			sum+=iHigher*iFactor+iLower+1;
			break;
		default:
			sum+=(iHigher+1)*iFactor;
			break;
		}
		iFactor*=10;
	}
	return sum;
}

int main()
{
	int x = 10;
	int y = 10;
	x = x++;
	y = ++y;
	printf("%d %d",x,y);
	
	unsigned int n;
	clock_t c;
	while(cin >> n)
	{
		c = clock();
		cout << f(n);
		c = clock() - c;
		cout << " Time Elasped: " << (c+0.0)/CLOCKS_PER_SEC<<" "<<c <<endl;
		
		c = clock();
		cout << count2(n);
		c = clock() - c;
		cout << " Time Elasped: " << (c+0.0)/CLOCKS_PER_SEC <<" "<<c <<endl;
	}
}
