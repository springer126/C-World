// FunctionObject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

class Complex
{
public:
	Complex(double value):real(value),vir(value){}
	double real;
	double vir;
};


class LongDouble
{
	friend LongDouble operator+(LongDouble &ld,int val)
	{
		std::cout << "friend LongDouble operator+(LongDouble & ,int)" << std::endl;
		LongDouble ld1(0.0);
		return ld1;
		
	}
public:
	LongDouble(double intVal):val(intVal){}
	operator double(){return val;}
	LongDouble operator+(const Complex &complex)
	{
		std::cout << "LongDouble operator+(const Complex &)" << std::endl;
		LongDouble ld1(0.0);
		return ld1;
	}
	long double val;
};

LongDouble operator+(const LongDouble &ld,double val)
{
	std::cout << "LongDouble operator+(const LongDouble &ld,double val)" << std::endl;
	LongDouble ld1(0.0);
	return ld1;
	
}

int _tmain(int argc, _TCHAR* argv[])
{
	const LongDouble ld(16.90);
	double res = ld+15.905;
	
	std::string s;
	std::vector<string> vec;
	while (std::cin >> s )
	{
		vec.push_back(s);
	}

	sort(vec.begin(),vec.end(),greater<string>());
	for(vector<string>::iterator beg = vec.begin();beg!=vec.end();beg++)
	{
		std::cout << *beg << std::endl;
	}
	return 0;
}

