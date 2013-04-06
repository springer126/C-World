#include "iostream"
#include "cmath"
using namespace std;

int main()
{
	double m,n,t;
	double i,j;
	while(scanf("%lf %lf %lf",&m,&n,&t)!=EOF)
	{
		i=pow((n-m-t)/(n-m),2)/2;
		j=0.5-i;
		printf("%0.3f\n",j);
	}
	return 0;
}