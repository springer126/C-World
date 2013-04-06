// Exception.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "exception"
#include "iostream"
#include <string>
#include <time.h>

using namespace std;

class MyException :public runtime_error
{
public:
	MyException(string &msg):runtime_error(msg.c_str())
	{
	}
	
	void output()
	{
		time_t t;
		time(&t);
		cout << t << endl; 
	}

	void what()
	{
		std::runtime_error::what();
		output();
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		//throw std::runtime_error("Exception¡­¡­");
		throw MyException(string("Exception¡­¡­"));
	}
	catch (MyException &e)
	{
		//std::cout << e.what()<< std::endl;
		e.what();
	}
	
	return 0;
}

