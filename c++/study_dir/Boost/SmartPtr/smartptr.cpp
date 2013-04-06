#include <iostream>
#include <string>
#include <boost/smart_ptr.hpp>
using namespace std;
using namespace boost;

typedef struct posix_file
{
	posix_file(const string &fille_name)
	{
		cout<<"Open file :"<<fille_name<<endl;
	}

	~posix_file()
	{
		cout<<"Close file"<<endl;
	}
};
/*
int main()
{
	int i = 0;
	scoped_ptr<string> p(new string("C++ Primier"));
	
	cout<< *p << " "<<p->size()<<endl;
	//p.get()->delete();
	scoped_ptr<int> p0(new int);
	if (p0)
	{
		*p0 = 100;
		cout << *p0 << endl;
	}
	
	p0.reset();
	assert(p0==NULL);
	scoped_ptr<posix_file> p1(new posix_file("/tmp/a.txt"));

	auto_ptr<int> ap(new int(100));
	//scoped_ptr initialized by auto_ptr and auto_ptr 's pointer is null
	scoped_ptr<int> sp(ap);
	
	ap.reset(new int(200));
	//assert(ap.get()==0);
	cout<< *ap << *sp <<endl;

	try
	{
		//scoped_ptr 拷贝构造函数和赋值函数都是私有的 不能通过赋值函数初始化 
		scoped_ptr<int> sp2;
		//boost::scoped_ptr<T>::operator =' : cannot access private member declared in class 'boost::scoped_ptr<T>
		//编译通不过
		//sp2 = sp;

	}
	catch(std::exception &e)
	{
		cout << e.what() <<endl;
	}
	
 	scoped_array<int> sa(new int[100]);
	for (int i = 0;i<100;i++)
	{
		sa[i] = i;
		cout << sa[i]<<endl;
	}


}
*/