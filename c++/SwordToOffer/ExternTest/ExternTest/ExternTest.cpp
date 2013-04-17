// ExternTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
extern "C" int add(int x,int y);

int _tmain(int argc, _TCHAR* argv[])
{
	printf("%d ",add(10,10));
	return 0;
}

