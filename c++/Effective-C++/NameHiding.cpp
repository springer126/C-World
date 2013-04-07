#include <iostream>
#include <string>
using namespace std;

struct Base
{
	void foo(int x)
	{
		cout << "Base foo x = " << x <<endl;
	}

protected:
	int bar;
public:
	double foo_bar;

};

struct Derived:Base
{
	using Base::foo;
	using Base::bar;
//	using Base::foo_bar;

	void foo(string s)
	{
		cout << "Derived foo string = "<<s <<endl;
	}

	bool bar(Base *b)
	{
		return foo_bar = b->foo_bar;
	}

	void foobar()
	{
		cout << "Derived foobar " <<endl;
		Base::bar = 1024;
	}

protected:
	string bar1;
};

int main()
{
	Derived d;
	d.foo(1024);

}
