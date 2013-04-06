// HelloBoost.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <list>
#include <boost/graph/vector_as_graph.hpp>
#include <boost/graph/graph_utility.hpp>
#include <boost/lexical_cast.hpp>
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	using boost::lexical_cast; 
	using namespace std;
	int a=lexical_cast<int>("123"); 
	double b=lexical_cast<double>("123.0123456789"); 
	string s0=lexical_cast<string>(a); 
	string s1=lexical_cast<string>(b); 
	cout<<"number: "<<a<<"  "<<b<<endl; 
	cout<<"string: "<<s0<<"  "<<s1<<endl; 
	int c=0; 
	try
	{ 
		c=lexical_cast<int>("abcd"); 
	} 
	catch(boost::bad_lexical_cast& e)
	{ 
		cout<<e.what()<<endl; 
	}

	std::cout << "==============================" << std::endl;
	enum {r,s,t,u,v,w,x,y,N};
	char name[] ="rstuvwxy";
	typedef std::vector<std::list<int> > Graph;
	std::cout << r << std::endl;
	Graph g(N);
	g[r].push_back(v);
	g[s].push_back(r);g[s].push_back(r);g[s].push_back(w);
	g[t].push_back(x);
	g[u].push_back(t);
	g[w].push_back(t);g[w].push_back(x);
	g[x].push_back(y);
	g[y].push_back(u);
	boost::print_graph(g,name);
	return 1; 


}


/*
#include <stdio.h>
int getcount(int n,int start)
{
	//printf("%d + %d = %d\n",start,n,n+start);
	if(2*start>n)
	{
		printf(" %d\n",n);
		return 0;
	}
	else
	{
		printf(" %d",start);
		return getcount(n-start,start+1)+1;
	}
	//return ( (n<2*start) ? 0 : getcount(n-start,start+1)+1);
}

int getCounts(int n)
{
	int Count=0;
	for(int i=1;i<(n+1)/2;++i)
	{//注意和和是n+1
		//printf(" i=%d %d ",i,getcount(n,i));
		Count+=getcount(n,i);
	}

	return Count;
}

int main()
{
	printf("%d\n",getCounts(19));
}
*/