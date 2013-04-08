#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

/*
 *fun函数中，p是实参的拷贝，p和str都是NULL，动态分配后，p指向新内存的地址，str不变 因此fun函数导致泄漏（没有delete）
 *
 *解决方法：
	1:fun(char* &p）【对引用的改变将反映到引用的对象】
 	2:char* fun()[返回动态分配内存的指针]
 */
void fun(char *p)
{
	p = new char[100];
	strcpy(p,"hello world!\n");
	printf("%s\n",p);
}


char* get()
{
	char *p = "Hello World\n";
	return p;
}

char *get2()
{
	char p[] = "Hello World\n";
	return p;
}

void func(char* &p)
{
	//p = new char[100];
	p = (char *)malloc(100);
	strcpy(p,"hello world!\n");
	printf("%s",p);
}

int main()
{
	char *str = NULL;
	//fun(str);
	func(str);
	printf("%s",str);

	if(str!=NULL)
	{
		free(str);
		printf("Free memmory!\n");
	}


	printf("%s",get());
	printf("%s",get2());
}
