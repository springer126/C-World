/**
 *输入若干无序区间[x1,y1][xn,yn],判断输入的源区间[x，y]是否在区间内
 *2013-03-27
 *author: wenhui
 */


#include <iostream>
#include <algorithm>
using namespace std;

struct Line
{
	int low;
	int high;
	bool operator<(const Line &l) const
	{
		return low<l.low;
	}
};

const int MAX = 10000;
const int N = 100;
Line lines[MAX];
int ncnt = 0;			//合并后区间的个数

/*
 * 以区间的low作为划分，找出key所在的区间
 */
int getIndex(int key)
{
	int u = 0,v = ncnt-1;
	int mid;
	while(u<=v)
	{
		//careful:use >>1 not /2
		mid = (u+v)>>1;
		if(key>=lines[mid].low)
			u = mid+1;
		else
			v = mid-1;
	}
	return v;
}

int main()
{
	int n,i,j;
	int x,y;
	cin >> n;
	for(i = 0;i<n;i++)
	{
		cin >> lines[i].low >> lines[i].high;
		cout << "lines["<<i+1<<"]: "<< lines[i].low<<","<<lines[i].high<<endl; 
	}

	sort(lines,lines+n);
	int lasthigh = lines[0].high;
	for(i = 1;i<n;i++)
	{
		if(lasthigh>=lines[i].low)
		{
			if(lasthigh<lines[i].high)
				lasthigh = lines[i].high;
		}
		else
		{
			lines[ncnt++].high = lasthigh;
			lines[ncnt].low = lines[i].low;
			lasthigh = lines[i].high;
		}
	}

	lines[ncnt++].high  = lasthigh;

	for(i = 0;i<ncnt;i++)
	{
		cout << "lines["<<i+1<<"]: "<< lines[i].low<<","<<lines[i].high<<endl; 
	}

	while(cin>>x>>y)
	{
		if(x>y)
		{
			cout << "Invalid interval!" <<endl;

		}
		else
		{
			i = getIndex(x);
			j = getIndex(y);
			cout <<i<<","<<j<<endl;
			if(i==j && y<=lines[i].high)
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "NO" <<endl;
			}
		}
	}
}
