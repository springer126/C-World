// TLinerList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "LinerList.h"

int _tmain(int argc, _TCHAR* argv[])
{
	LinerList<int> list(5);
	list.Insert(0,2);
	list.Insert(1,6);
	int z;
	list.Find(1,z);
	std::cout << z << std::endl;
	list.Insert(2,7);
	std ::cout << list << std::endl;

	LinerList<int> list1(list);
	list1.Insert(3,3);
	list1.Insert(4,89);
	std ::cout << list1 << std::endl;
	
	LinerList<int> list3 = list1.Half();
	std ::cout << list3 << std::endl;

	return 0;
}

