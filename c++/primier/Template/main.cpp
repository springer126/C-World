#include "MyQueue.h"
#include "MyQueueItem.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Test.h"
#include "Test.cpp"

template <class T,class V>
T& output(T &t,V v)
{
	t<<v<<std::endl;
	
	return t;
}

int main()
{
	std::string s;
	output(std::cout,"Hello wenhui");
	std::ofstream out("G:\\test.txt",std::ios::app);
	output(out,"Hello wenhui");
	
	std::ostringstream oos(s);
	output(oos,"think in c++");
	std::cout<<oos.str()<<std::endl;


	std::cout <<"=========================="<<std::endl;
	MyQueue<int> q;
	q.push(10);
	q.push(11);
	q.push(12);
	q.push(13);
	q.push(14);

	MyQueue<int> q1 = q;
	
	while (!q.empty())
	{
		std::cout << q.front() <<std::endl;
		q.pop();
	}

	while (!q1.empty())
	{
		std::cout << q1.front() <<std::endl;
		q1.pop();
	}


	
	Test<int> t(10000);
	t.PrintSelf();

}