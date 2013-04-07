#include "Derived.h"
#include <iostream>

class LongDouble
{
	public:
		LongDouble(double i):d(i){}
	private:
		double d;
	};

void cal(int){std::cout << "cal(int)" <<std::endl;}
void cal(LongDouble d){std::cout << "cal(LongDouble d)" <<std::endl;}



int main()
{
	double t = 10;	
	cal(t);
	
	Derived d;
	//Base b;
	std::cout <<"size of d:"<<sizeof(d)<<std::endl;
	int x = 0;
	Base *p = &d;
	/*
	d.mf1();
	d.mf1(2);
	d.mf2();
	d.mf3();
	d.mf3(x);
	*/
	
	std::cout <<*((int*)&d+1)<<std::endl;
	
	p->mf1();
	p->mf1(2);
	std::cout <<*((int*)&d+1)<<std::endl;
	p->mf2();
	p->mf3();
	p->mf3(x);
	p->fun();
	}
