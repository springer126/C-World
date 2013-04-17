#include <iostream>
#include <cassert>
using namespace std;

#define max(a,b) \
		({int _a = (a);int _b = (b);_a>_b?_a:_b;})

void testWithAssert(int *ptr)
{
	assert(ptr!=NULL);
	cout << "assert test" << endl;
}

int main()
{
	int a,b;

	cout << "Hello World1"<<endl;
	cin >> a >> b;
	cout << max(a,b)<<endl;

	int *p = NULL;
	testWithAssert(p);
}
