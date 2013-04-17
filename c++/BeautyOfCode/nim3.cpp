#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMin(vector<int> &vec)
{
	int i=1;
	sort(vec.begin(),vec.end());
	vector<int>::iterator beg = vec.begin(),end = vec.end();
	for(;beg!=end && i==*beg;beg++,i++);
	return i;
}

bool nim(int x,int y)
{
	vector<int> vec;
	int a = 1;
	int b = 2;
	vec.push_back(a);
	vec.push_back(b);
	if(x==y)
		return true;
	int temp;
	if(x>y)
	{
		temp = x;x = y;y = temp;
	}
	
	int n = 2;
	while(x>a)
	{
		a = getMin(vec);
		b = a+n;
		n++;
		vec.push_back(a);
		vec.push_back(b);
	}
	
	if(a==x && b==y)
		return false;
	else
		return true;
}

int main()
{
	int x,y;
	while(cin >> x >> y)
		cout << nim(x,y) << endl;
	}
