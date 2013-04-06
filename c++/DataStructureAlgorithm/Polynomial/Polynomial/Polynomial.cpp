// Polynomial.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "Term.h"
#include "TPolynomial.h"
using namespace std;

ostream& operator<<(ostream &out,Term &t)
{
	out <<"("<< t.data<<" , "<<t.power<<") ";
	return out;
}

ostream& operator<<(ostream &out,TPolynomial &p)
{
	Term *first = p.head->next;
	while (first->next!=p.head->next)
	{
		out << *first;
		first = first->next;
	}
	return out;
}

int Compare(const char* c1,const char* c2)
{
	std::cout << "Function" << std::endl;
	return strcmp(c1,c2);
}

template <class T>
int Compare(const T &t1,const T &t2)
{
	std::cout << "Template" << std::endl;
	return t1<t2;
}

template <>
int Compare<const char*>(const char* const &c1,const char* const &c2)
{
	std::cout << "Specific Template" << std::endl;
	return strcmp(c1,c2);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a = 1,b=2;
	char *name1 = "wenhui";
	char *name2 = "meiling";

	const char *name3 = "wenhui";
	const char *name4 = "meiling";

	Compare(a,b);
	Compare(name1,name2);
	Compare(name3,name4);

	TPolynomial t,t1;
	t.Input();
	std::cout << t.Degree() << std::endl;
	std::cout << t<< std::endl;
	std::cout << t.Value(2)<< std::endl;

	t1.Input();
	std::cout << t1<< std::endl;
	t1.Add(t);
	std::cout << t1<< std::endl;
	return 0;
}

