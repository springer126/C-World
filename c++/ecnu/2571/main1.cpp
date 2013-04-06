#define _MAIN1_

#include "iostream"
#include "string"
#include "cmath"
using namespace std;

int main()
{
	int N;
	int addr[4];
	int i,j,temp;
	string s;

	cin>>N;

	while(N-->0)
	{
		i=0;
		cin>>s;
		for(j=0;j<32;j++)
		{
			if(j%8==0)
				temp=0;
			temp+=(int)(pow(2.0,7-j%8)*(s[j]-'0'));

			if(j%8==7)
			{
				addr[i]=temp;
				i++;
			}	
		}

		printf("%d.%d.%d.%d\n",addr[0],addr[1],addr[2],addr[3]);

	}
	return 0;
}