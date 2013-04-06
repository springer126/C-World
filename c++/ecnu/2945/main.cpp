#include "iostream"
#include "string"
using namespace std;

int main()
{
	int N;
	string s[20];
	int v[20];
	int i=0,max=0;
	
	cin>>N;
	for(i=0;i<N;i++)
	{
		cin>>s[i]>>v[i];
		if(max<v[i])
			max=v[i];
	}

	for(i=0;i<N;i++)
	{
		if(max==v[i])
			cout<<s[i]<<endl;
	}

	return 0;
}