// GenericHandle.cpp : �������̨Ӧ�ó������ڵ㡣
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

