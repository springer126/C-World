// TwoStacksSimulateQueue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyQueue.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	CMyQueue<int> q;
	q.append(2);
	q.append(7);
	q.append(3);
	q.append(5);
	int i =  q.del();
	int j = q.del();
	std::cout <<"First:"<< i<<" , Second:"<<j<<std::endl;
	int k = 0;
	return 0;
}

