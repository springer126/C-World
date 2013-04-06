#include <iostream>
#include <string.h>
#include <algorithm>
#include <numeric>
using namespace std;

#define MAX 100

int nPerson[MAX];//nPerson[i] stands for persons head to ith floor

int main()
{
	int n;
	int i,j,k;
	int floors;
	while(cin>>n)
	{
		floors = 0;
		memset(nPerson,0,MAX);
		for(i = 0;i<n;i++)
		{
			cout << "No."<<(i+1)<<" Destination Floor:";
			cin>>j;
			if(1<= j <MAX)                //no one will ride elevator to 1th floor
				nPerson[j]++;
		}
	
		
		int n1 = 0;
		int n2 = 0;
		int n3 = 0;
		//accumulate(nPerson,nPerson+MAX,floors);
		for(i = 1;i<MAX;i++)
		{
			floors += nPerson[i]*(i-1);
			n3+=nPerson[i];
		}
		cout << floors <<endl;

		for(k = 2;k<MAX;k++)
		{
			if(n1+n2<n3)
			{
				n1 += n2;
				floors = floors+(n1+n2-n3);
				n2 = nPerson[k];
				n3 -=nPerson[k];
				std::cout << "Current Floor:"<<k << ",Floors:"<<floors<<endl;
			}
			else
			{
				std::cout << "Target Floor:"<<k << ",Floors:"<<floors<<endl;
				break;
			}
		}

	}


}
