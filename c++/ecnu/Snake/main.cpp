#include "utility"
#include "iostream"
using namespace std;

//int direction[6]={0,1,1,2,3,1};

int main(int argc, char* argv[])
{
	int H,W,T;

	char A[101][101];

	while(scanf("%d %d %d",&H,&W,&T)!=EOF)
	{
		int dir;
		int ret=0;
		int i;
		pair<int,int> location(0,0);
		int prev1=0,prev2=1,prev;
		
		for(i=0;i<H;i++)
			scanf("%s",A[i]);

		for(i=0;i<T+1;i++)
		{
			if(A[location.first][location.second]!='.')
				ret+=A[location.first][location.second]-'0';

			
			if(i==0)
				dir=prev1%4;
			else if(i==1)
				dir=prev2%4;
			else
			{
				prev=prev1+prev2;
				prev1=prev2%4;
				prev2=prev%4;
				dir=prev2;
			}
			
			//dir = direction[i%6];
		
			while((dir==0 && location.first==0) ||(dir==1 && location.second==W-1) ||
					(dir==2 && location.first==H-1) ||(dir==3 && location.second==0))
				dir=(dir+1)%4;

			switch(dir)
			{
			case 0:
				location.first--;
				break;
			case 1:
				location.second++;
				break;
			case 2:
				location.first++;
				break;
			case 3:
				location.second--;
				break;
			}
			
			
		}
		
		cout<<ret<<endl;
	}

	return 0;
 
}