// NewHandler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <new.h>
#include<stdlib.h>
using namespace std;

void __cdecl newhandler()

{

	cout << "The new_handler is called:" << endl;

	throw bad_alloc();

	return;

}

int _tmain(int argc, _TCHAR* argv[])
{
	set_new_handler (newhandler);

	try
	{
		while (1)
		{
			new int[5000000];
			cout << "Allocating 5000000 ints." << endl;
		}
	}
	catch ( exception e )
	{
		cout << e.what() << " xxx" << endl;
	}

	return 0;
}

