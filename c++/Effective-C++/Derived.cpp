#include "Derived.h"
#include <iostream>
using namespace std;

extern int defaultFunc(const Base& base);

Derived::Derived(int x,CalcFunc func):Base(x,func){}
	
void Derived::mf1()
{
	cout << "Derived::mf1():";
    cout << "x = "<<n <<endl;		
}
	
void Derived::mf1(int x)
{
	cout << "Derived::mf1():";
    cout << "x = "<<x+1 <<endl;		
}

void Derived::mf3()
{
	cout << "Derived::mf3()" <<endl;		
}
	
void Derived::mf4(double x)
{
	cout << "Derived::mf4(double x)" <<endl;		
}
	
	
void Derived::nvi()
{
		cout << "nvi in derived" <<endl;
}
		
