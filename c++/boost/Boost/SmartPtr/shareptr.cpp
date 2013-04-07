#include <boost/smart_ptr.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <iostream>
#include <string>
#include <map>
#include <istream>
#include <exception>
#include <sstream>

using namespace std;

int &get(int (&a)[10],int index)
{
	return a[index];
}

int main()
{
	/*boost::shared_ptr<int> sp(new int(100));
	boost::shared_ptr<int> sp1(sp);
	std::cout<<*sp << *sp1 <<std::endl;*/

	/*
	int ival;
	while(std::cin>>ival,!std::cin.eof())
	{
		if(std::cin.bad())
			std::cerr<<"IO CORRUPTED.";
		if(std::cin.fail())
		{
			std::cerr<<"Bad data";
			//std::cin.clear(istream::goodbit);
			//std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			continue;
		}
		std::cout << ival <<std::endl;
	}
	*/
	
	string line,word;
	while (getline(std::cin,line))
	{
		istringstream stream(line);
		while (stream >> word)
		{
			std::cout << word << std::endl;
		}
	}

	typedef boost::shared_ptr<std::string> sp_t;
	std::map<sp_t,int> m;
	sp_t sp(new std::string("one"));
	m[sp] = 100;
	std::cout<<m[sp]<<std::endl;

	int a[10]={1,2,3,4,5,6,7,8,9,10};
	for(int i =0;i<10;i++)
	{
		get(a,i) = 0;
	}

	for (int i = 0;i<10;i++)
	{
		std::cout<<a[i]<<std::endl;
	}

	boost::adjacency_list<> mygraph;
	add_edge(1, 2, mygraph);
	add_edge(1, 3, mygraph);
	add_edge(1, 4, mygraph);
	add_edge(2, 4, mygraph);
}