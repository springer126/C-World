#include <iostream>
#include <climits>

int cal(int a[],int len,int &start,int &end)
{
	int max = INT_MIN;
	int temp = 0;
	int curStart;
	start = end = 0;
	
	for(int i=0;i<len;i++)
	{
		temp+=a[i];
		if(temp>=0)
		{
			if(max<temp)
			{
				start = curStart;
				max = temp;
				end = i;
			}
		}else
		{
			temp = 0;
			curStart = i+1;
		}
	}
	return max;
}

int main()
{
	int a[15] = {-10,1,2,6,-8,7,1,-9,3,4,-5,-23,3,7,-21};
	int b[6] = {-2,11,-4,13,-5,-2};
	int c[6] = {-2,-4,-1,-10,-11,-20};
	int max;
	int start,end;
	max = cal(a,15,start,end);
	std::cout << max<<" ["<<start<<","<<end<<"]"<< std::endl;
}
