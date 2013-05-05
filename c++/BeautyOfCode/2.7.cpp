#include <iostream>
using namespace std;

bool isEven(int i)
{
	return i%2==0;
}

int gcd(int m, int n)
{
	if(m<n)
		return gcd(n,m);
	else
	{
		if(n==0)
			return m;
		else
			return gcd(n,m%n);
	}
}

int gcd2(int m,int n)
{
	if(m<n)
		return gcd2(n,m);
	else
	{
		if(n==0)
			return m;
		else
			return gcd2(n,m-n);
	}
}

int gcd3(int m,int n)
{
	if(m<n)
		return gcd(n,m);
	
	if(n==0)
		return m;
	
	if(isEven(m))
	{
		if(isEven(n))
			return gcd3(m>>1,n>>1)<<1;
		else
			return gcd3(m>>1,n);
	}
	else
	{
		if(isEven(n))
			return gcd3(m,n>>1);
		else
			return gcd(m,m-n);
	}
}

int main()
{
	clock_t start;
	start = clock();
	cout << start << endl;
	cout << gcd(100000,64)<<endl;
	cout << clock()  - start << endl;
	
	cout << "=====================" <<endl;
	
	start = clock();
	cout << start << endl;
	cout << gcd2(100000,64)<<endl;
	cout << clock()  - start << endl;
	
	cout << "=====================" <<endl;
	
	start = clock();
	cout << start << endl;
	cout << gcd3(81,63)<<endl;
	cout << clock()  - start << endl;
}
