/*
物品 0 1 2 3
重量 5 3 2 1
价值 4 4 3 1
*/

#include <IOSTREAM>
using namespace std;

int w[4] = {5,3,2,1};
int v[4] = {4,4,3,1};
int option[4];
int cop[4];
int maxv;

//compute the largest value from 1 to opt 
int fun(int weight,int k)
{
	int value,temp=0;
	if(weight ==0)
	{
		return 0;
	}
	else if(k==1)
	{
		value = (weight/w[0])*v[0];
		return value;
	}
	else
	{
		/*
		int i = weight/w[k-1];
		if(i>0)
		{
			value = i*v[k-1]+fun(weight-i*w[k-1],k-1);
			for(int j=i-1;j>0;j--)
			{
				temp = j*v[k-1]+fun(weight-j*w[k-1],k-1);
				if(value<temp)
					value = temp;
			}
		}
		else
		{
			value = fun(weight,k-1);
		}
		*/
		value = fun(weight,k-1);
		for(int i=0;i <= weight/w[k-1];i++)
		{
			temp = i*v[k-1]+fun(weight-i*w[k-1],k-1);
			if(value<temp)
					value = temp;
		}
		return value;
	}
}


int main()
{
	int weight;
	maxv = 0;
	while(cin>>weight)
	{
		cout << fun(weight,4) <<endl;
	}
	return 0;
}