#include "iostream"
#include "utility"
#include "cmath"
#include "cstdio"
using namespace std;

pair<int,int> v[100];
int n;

double cal(int index)
{
	bool flag;
	int k=index+1;

	int x1=v[index].first;
	int y1=v[index].second;
	if(index==n-1)
		k=0;
	int x2=v[k].first;
	int y2=v[k].second;
	if(x2*y1==y2*x1)
		return 0;
	else if(x1==0)
	{
		if(y1>0)
			flag=x2>0?false:true;
		else
			flag=x2>0?true:false;
	}
	else if(x2==0)
	{
		if(y2>0)
			flag=x1>0?true:false;
		else
			flag=x1>0?false:true;
	}
	else
	{
		double k1=y1/x1;
		double k2=y2/x2;
		if(k1>k2)
			flag=false;
		else
			flag=true;
	}

	double a=sqrt((double)(x1*x1+y1*y1));
	double b=sqrt((double)(x2*x2+y2*y2));
	double c=sqrt((double)((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
	double s=0.5*(a+b+c);

	if(flag)
		return sqrt(s*(s-a)*(s-b)*(s-c));
	else
		return -sqrt(s*(s-a)*(s-b)*(s-c));
}

int main()
{
	
	int i;
	double result;
	while(true)
	{
		cin>>n;
		if(n==0)
			break;

		result=0;
		for(i=0;i<n;i++)
			cin>>v[i].first>>v[i].second;
			
		for(i=0;i<n;i++)
			result+=cal(i);

		printf("%0.1f\n",result);

	}
	return 0;
}