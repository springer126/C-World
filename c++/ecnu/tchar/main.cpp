#include <TCHAR.h>
#include <cstdio>

int main()
{
	TCHAR* s = "ajshdi218jÎåÊå¿ª½±ºÅaisdi";
	//strlen(L"ahkashduid");
	printf("%d\n",_tcslen(s));
	printf("%d\n",strlen(s));
	return 0;
}