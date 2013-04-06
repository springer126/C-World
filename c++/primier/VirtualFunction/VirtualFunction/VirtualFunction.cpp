// VirtualFunction.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


class Base
{
public:
	virtual void f(){cout << "Base::f" <<endl;}
	virtual void g(){cout << "Base::g" <<endl;}
	virtual void h(){cout << "Base::h" <<endl;}
};

class Base2
{
public:
	virtual void f(){cout << "Base2::f" <<endl;}
	virtual void g(){cout << "Base2::g" <<endl;}
	virtual void h(){cout << "Base2::h" <<endl;}
};

class Derived :public Base2,public Base
{
	 virtual void f(){cout << "Derived::f" <<endl;}
	 virtual void g1(){cout << "Derived::g1" <<endl;}
	 virtual void h1(){cout << "Derived::h1" <<endl;}
};



int _tmain(int argc, _TCHAR* argv[])
{
	typedef void (*FUN)(void);
	FUN pFun = NULL;
	Base b;
	cout << "Base addr = " << &b << endl;

	pFun =  (FUN)*((int *)*(int *)&b+0);
	pFun();
	pFun =  (FUN)*((int *)*(int *)&b+1);
	pFun();
	pFun =  (FUN)*((int *)*(int *)&b+2);
	pFun();

	cout << "=================================" <<endl;

	Derived d;
	Base *p1 = &d;
	Base2 *p2 = &d;
	p1->f();
	p2->f();
	cout << "Derived addr = " << &d << endl;

	pFun =  (FUN)*((int *)*(int *)&d+0);
	pFun();
	pFun =  (FUN)*((int *)*(int *)&d+1);
	pFun();
	pFun =  (FUN)*((int *)*(int *)&d+2);
	pFun();
	pFun =  (FUN)*((int *)*(int *)&d+3);
	pFun();
	pFun =  (FUN)*((int *)*(int *)&d+4);
	pFun();
	pFun =  (FUN)*((int *)*(int *)&d+5);
	pFun();
	return 0;
}

