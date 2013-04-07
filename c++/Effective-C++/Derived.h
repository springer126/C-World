#include "Base.h"
#include <iostream>

extern int myFunc(const Base& base);
extern int defaultFunc(const Base& base);

class Derived :public Base
{
	public:
		//using Base::mf1;
		//using Base::mf3;
		using Base::n;
		explicit Derived(int x = 0,CalcFunc func = defaultFunc);

		void mf1();
		void mf1(int x);
		void mf3();
		void mf4(double x);
	
	private:
		void nvi();
	};
