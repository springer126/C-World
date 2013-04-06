#include <ctime>
#include <iostream>
#include <boost/timer.hpp>
using namespace std;
using namespace boost;


int main()
{
	cout<<std::clock()<<endl;
	timer t;
	cout<<t.elapsed()<<endl;
	for (int i=0;i<1000000;i++)
	{
		//sleep(1000);
		if(i%2==0)
			continue;

	}
	cout<<std::clock()<<endl;
	cout<<t.elapsed()<<endl;
	return 0;
}