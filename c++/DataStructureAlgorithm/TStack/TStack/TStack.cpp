// TStack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Stack.h"
int _tmain(int argc, _TCHAR* argv[])
{
	Stack<int> s;
	s.Add(10);
	s.Add(11);
	s.Add(12);
	std::cout << s.Top()<<std::endl;

	LinkStack<int> ls;
	ls.Add(0);
	ls.Add(1);
	ls.Add(2);
	std::cout << ls.Top()<<std::endl;

	return 0;
}

