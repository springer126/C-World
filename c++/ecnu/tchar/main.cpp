#include <TCHAR.h>
#include <cstdio>

int main()
{
	TCHAR* s = "ajshdi218j���忪����aisdi";
	//strlen(L"ahkashduid");
	printf("%d\n",_tcslen(s));
	printf("%d\n",strlen(s));
	return 0;
}