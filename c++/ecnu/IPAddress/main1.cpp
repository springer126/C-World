#define _MAIN_

#include "iostream"
#include "string"
#include "cmath"
using namespace std;

int main()
{
	string s;
	int N;
	int addr[4];
	int k,temp,j;

	cin>>N;
	while(N-->0)
	{
		cin>>s;
		k=0;
		for(j=0;j<32;j++)
		{
			if(j%8==0)
				temp=0;
			temp+=(int)(pow(2,7-j%8)*(s[j]-'0'));

			if(j%8==7)
			{
				addr[k]=temp;
				k++;
			}	
		}

		printf("%d.%d.%d.%d\n",addr[0],addr[1],addr[2],addr[3]);
	}

	return 0;
}