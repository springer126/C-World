#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

typedef priority_queue<int,vector<int>,greater<int> > PQ_INT;


void test()
{
	cout << rand()%100 << endl;	
}

int main()
{
		test();
		
		PQ_INT pqueue_int;
		srand((unsigned)time( NULL ) );
		for(int i = 0;i<10;i++)
		{
			pqueue_int.push(rand()%100);
		}
		
		
		pqueue_int.push(78);
		
		while(!pqueue_int.empty())
		{
			cout << pqueue_int.top() << " ";
			pqueue_int.pop();
		}
		
		cout << endl;
}