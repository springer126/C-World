#include "iostream"
#include "cmath"
using namespace std;

//һ���ռ�����ܱ�n��ƽ��ָ��n^3/6+5n/6+1������

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
