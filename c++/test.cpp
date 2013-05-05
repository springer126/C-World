#include <iostream>
#include <cassert>
#include <string>
using namespace std;

class A
{
public:
	 int a;
};

class B : virtual public A
{
public:
	 int b;
};

class C :virtual public A
{
public:
	 int c; 
};

class D : public B, public C
{
public:
	 int d;
};

class Trace
{
private:
	int n;
public:
	Trace(int i):n(i){}

	void trace(const string &str)
	{
		cout << str << endl;
	}
};

#define max(a,b) \
		({int _a = (a);int _b = (b);_a>_b?_a:_b;})

void testWithAssert(int *ptr)
{
	assert(ptr!=NULL);
	cout << *ptr << endl;
}

int main()
{

	cout << sizeof(A)<<" "<<sizeof(B)<<" "<<sizeof(C)<<" "<<sizeof(D)<<endl;
	B obj;
	D obj2;
	cout << *((int *)&obj) << endl;
	cout << *((int *)&obj2) << endl;
	
	
	
	int a,b;
	
	Trace t(10);
	string str("this is a trace string");
	t.trace(str);
	cout << "Hello World1"<<endl;
	cin >> a >> b;
	cout << max(a,b)<<endl;

#ifdef DEBUG
	cout << "DEBUG IS DEFINED" << endl;
#endif

	int *p = NULL;
	testWithAssert(p);
}
