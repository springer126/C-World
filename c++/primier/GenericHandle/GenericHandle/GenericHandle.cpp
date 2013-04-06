// GenericHandle.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Handle.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Handle<int> hp(new int(32));
	Handle<int> hp2(hp);
	std::cout << *hp2 << std::endl;
	*hp2 = 10;
	std::cout << *hp << std::endl;
	return 0;
}

