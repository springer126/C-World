#include <iostream>
#include <string>

template <class T>
class NameObject
{
public:
	NameObject(std::string &name,const T &value):nameValue(name),objectValue(value)
	{
		//nameValue = 
	}
	
	
	/**
	 当nameValue为指向no-const对象的引用时，无法用char ＊初始化
	 */
	 
	NameObject(const char *name,const T &value):nameValue(name),objectValue(value)
	{
	}
	
	NameObject(const NameObject &rhs):nameValue(rhs.nameValue),objectValue(rhs.objectValue)
	{
	}
	
	NameObject& operator=(const NameObject &rhs)
	{
		nameValue = rhs.nameValue;
		objectValue = rhs.objectValue;
		return *this;
	}
	
	virtual void Display()
	{
		std::cout << nameValue << " , "<< objectValue << std::endl;
	}
	
private:
	std::string nameValue;
	T objectValue;
};

class Name : public NameObject<int>
{
public:
	Name(std::string &name, const int &value,  const int &i):NameObject(name,value),age(i){}
	
	Name(const Name &rhs):NameObject(rhs),age(rhs.age)
	{
	}
	
	Name& operator=(const Name &rhs)
	{
		age = rhs.age;
		return *this;
	}
	
	void Display()
	{
		NameObject::Display();
		std::cout <<" age :"<< age << std::endl;
	}
private:
	int age;
};

int main()
{
	std::string name("white dog");
	std::string oldDog("old dog");
	NameObject<int> no1(name,21);
	no1.Display();
	NameObject<int> no2(oldDog,22);
	no2.Display();
	/*
	 * NameObject.cpp:5:7: 错误： non-static reference member ‘std::string& NameObject<int>::nameValue’, can’t use default assignment operator
	 * NameObject.cpp:5:7: 错误： non-static const member ‘const int NameObject<int>::objectValue’, can’t use default assignment operator
	 */
	no2 = no1;
	no2.Display();
	std::cout << "=============================" << std::endl;
	NameObject<int> *n1 = new Name(name,12,12);
	n1->Display();
	
	Name n2(name,13,12);
	n2.Display();
	Name n3(n2);
	n3.Display();
	
	Name n4 = n2;
	n4.Display();
}
