#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;


/**
 *
 类似的方法可以解决0-1背包问题，算法同样需要伪多项式时间。
 我们同样假定w1, ..., wn和W都是正整数
 我们将在总重量不超过Y的前提下，前j种物品的总价格所能达到的最高值定义为A(j, Y)。
 A(j, Y)的递推关系为：
 A(0, Y) = 0
 A(j, 0) = 0
 如果wj > Y, A(j, Y) = A(j - 1, Y)
 如果wj ≤ Y, A(j, Y) = max { A(j - 1, Y), pj + A(j - 1, Y - wj) }
 通过计算A(n, W)即得到最终结果。为提高算法性能，我们把先前计算的结果存入表中
 因此算法需要的时间和空间都为O(nW)，通过对算法的改进，空间的消耗可以降至O(W)
 *
 */



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

const int N = 100;

int t,n;
float p;
struct Bank banks[N];
int profit[N+1][N+1]; //profit[i][j]表示在概率和小于等于j/100前提下，偷前i个银行可以偷的最大值

int cal()
{
  //  std::sort(banks,banks+n);
	
	int i,j,k;
	float temp;
	temp = p*100;
	int T = (int)temp;
	/*
	profit[0][T] = 0;
	for(i=1;i<=n;i++)
		profit[i][T] = INT_MIN;
	*/
	memset(profit,0,(N+1)*(N+1));
	for(i=0;i<n;i++)
	{
		temp = banks[i].pj*100;
		k = int(temp);
		//cout << banks[i].pj*1000<<" "<<banks[i].pj*1000/10;
		cout <<" "<<banks[i].pj<<" , "<< k << endl;
		if(k<=T)
		{
			for(j=0;j<k;j++)
			{
				profit[i+1][j] = profit[i][j];
			}
			for(j=k;j<=T;j++)
			{
				profit[i+1][j] = (profit[i][j]>(profit[i][j-k]+banks[i].mj))?(profit[i][j]):(profit[i][j-k]+banks[i].mj);
				cout << "profit["<<i+1<<"]["<<j<<"] = "<< profit[i+1][j] <<endl;
			}
		}
		else
		{
			for(j=0;j<=T;j++)
			{
				profit[i+1][j] = profit[i][j];
			}
		}
	}

	for(i = 0;i<n;i++)
	{
		cout << "profit["<<i+1<<"]["<<T<<"] = "<< profit[i+1][T] <<endl;
	}
	/*
	for(i = 0;i<n+1;i++)
	{
		for(j = 0;j<T+1;j++)
			cout << profit[i][j]<<" ";
		cout <<endl;
	}
	*/

	return profit[n][T];
}

int main()
{
	int i,j;
	if(cin>>t)
	{
		for(i=0;i<t;i++)
		{
			if(cin >> p >> n)
			{
				srand (time(NULL));
				for(j=0;j<n;j++)
				{
					cin >> banks[j].mj >> banks[j].pj;
					//banks[j].mj = rand()%10+1;
					//banks[j].pj = rand()%100/100.0;
					//cout << "banks["<<j+1<<"] = "<< banks[j].mj<<","<< banks[j].pj<<endl;
				}
			}
			cout << cal() << endl;
		}
	}
}
