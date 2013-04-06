#include "iostream"
#include "cmath"
using namespace std;

//一个空间最多能被n个平面分割成n^3/6+5n/6+1个部分

int main()
{
	int n,sum;
	cin>>n;
	while(n!=0)
	{
		sum=((int)pow(n,3.0)+5*n+6)/6;
		cout<<sum<<endl;
		cin>>n;
	}

	return 0;
}
