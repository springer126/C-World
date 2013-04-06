#include "iostream"
#include "cmath"
using namespace std;

int main()
{
	int n;
	double ans;
	cin>>n;
	while(n!=0)
	{
		ans=(double)log10(double(n))*n;
		ans-=int(ans);
		cout<<(int)pow(10,ans)<<endl;
		cin>>n;
	}

	return 0;
}
