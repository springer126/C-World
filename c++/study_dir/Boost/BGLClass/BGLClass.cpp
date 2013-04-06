// BGLClass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <boost/graph/adjacency_list.hpp>
#include <boost/tuple/tuple.hpp>
enum family {Jeanie,Debbie,Rick,John,Amanda,Margaret,Benjamin,N};
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace boost;
	const char* name[] ={"Jeanie","Debbie","Rick","John","Amanda",
		"Margaret","Benjamin"};
	//adjacency_list<vecS,vecS,directedS> g(N);
	adjacency_list<vecS,vecS,directedS> g(N);
	add_edge(Jeanie,Debbie,g);
	add_edge(Jeanie,Rick,g);
	add_edge(Jeanie,John,g);
	add_edge(Debbie,Amanda,g);
	add_edge(Rick,Margaret,g);
	add_edge(John,Benjamin,g);

	graph_traits<adjacency_list <> >::vertex_iterator i,end;
	graph_traits<adjacency_list<> >::adjacency_iterator ai, a_end;
	property_map<adjacency_list<>,vertex_index_t >::type index_map = get(vertex_index,g);
	
	for (tie(i,end) = vertices(g);i!=end;i++)
	{
		std::cout << name[get(index_map,*i)];
		tie(ai,a_end) = adjacent_vertices(*i,g);
		if(ai==a_end)
			std::cout << " has no children " << std::endl;
		else
			std::cout << " is parent of " <<std::endl;
		for (;ai!=a_end;++ai)
		{
			std::cout << name[get(index_map,*ai)];
			if(boost::next(ai)!=a_end)
			{
				std::cout <<",";	
			}
			std::cout <<std::endl;
		}
	}
 	return 0;
}

