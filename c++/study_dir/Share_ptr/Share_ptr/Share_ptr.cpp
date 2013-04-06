// Share_ptr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <memory>
#include <stdio.h>
using namespace std;

class student
{
protected:
	std::string name;
	int age;
public:
	student(std::string name,int age):name(name),age(age)
	{

	}

	student(const student& stu)
	{
		this->name=stu.name;
		this->age=stu.age;
	}

	student& operator=(const student& stu)
	{
		name = stu.name;
		age = stu.age;
		return *this;
	}

	void print()
	{
		std::cout <<"name:" <<name << "  age:" << age << std::endl;
	}
};

void testAuto_ptr(student *pStu)
{
	std::auto_ptr<student> pv(pStu);
	//std::cout<<pv->name<<" "<<pv->age<<std::endl;
	pv->print();
	std::cout<<"The student object which pStu pointed is deleting..."<<std::endl; 
}

void testShare_ptr()
{
	/*std::tr1::shared_ptr<student> pv(new student("helloworld",22));
	pv->print();*/
}

void test()
{
	student *s = new student("meiling",22);
	testAuto_ptr(s);
	if (s==NULL)
	{
		std::cout<<"The student object which s pointed is not existed..."<<std::endl; 
	} 
	else
	{
		std::cout<<"The student object which s pointed is existed..."<<std::endl; 
	}
}

void println(const std::string &str)
{
	std::cout<<"================================\n"<<std::endl;
	std::cout<<str<<std::endl;
	std::cout<<"================================\n"<<std::endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	
	student s("wenhui",10);
	s.print();
	
	test();

	std::string str;
	println(str);
	return 0;
}



