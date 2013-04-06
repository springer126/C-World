// LinerList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LinerList.h"

int _tmain(int argc, _TCHAR* argv[])
{
	LinerList<int> L(5);
	L.Insert(0,2);
	L.Insert(1,6);
	int z;
	L.Find(1,z);
	std::cout << z << std::endl;
	return 0;
}

