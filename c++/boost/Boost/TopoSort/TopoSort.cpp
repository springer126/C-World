// TopoSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <deque>
#include <vector>
#include <list>
#include <iostream>
#include <boost/graph/vector_as_graph.hpp>
#include <boost/graph/topological_sort.hpp>
#include <boost/graph/adjacency_list.hpp>

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace boost;
	using namespace std;
	const char *tasks[] = {
		"pick up kids from school",
		"buy groceries (and snacks)",
		"get cask at atm",
		"drop off kids at soccer practice",
		"cook dinner",
		"pick up kids from soccer",
		"eat dinner"
	};
	const int n_tasks = sizeof(tasks)/sizeof(char*);

	std::vector<std::list<int> >g(n_tasks);
	g[0].push_back(3);
	g[1].push_back(3);
	g[1].push_back(4);
	g[2].push_back(1);
	g[3].push_back(5);
	g[4].push_back(6);
	g[5].push_back(6);

	std::deque<int> topo_order;
	topological_sort(g,std::front_inserter(topo_order),
		vertex_index_map(identity_property_map()));
	int n =1;
	for (std::deque<int>::iterator i =topo_order.begin();
		i !=topo_order.end(); ++i, ++n)
		std::cout <<tasks[*i]<<std::endl;
	
	std::cout << "==============================="<<std::endl;
	boost::adjacency_list<listS,vecS,directedS> g1(n_tasks);
	add_edge(0,3,g1);
	add_edge(1,3,g1);
	add_edge(1,4,g1);
	add_edge(2,1,g1);
	add_edge(3,5,g1);
	add_edge(4,6,g1);
	add_edge(5,6,g1);
	std::deque<int> topo_order1;
	topological_sort(g1,std::front_inserter(topo_order1),
		vertex_index_map(identity_property_map()));
	int m =1;
	for (std::deque<int>::iterator i =topo_order1.begin();
		i !=topo_order1.end(); ++i, ++m)
		std::cout <<tasks[*i]<<std::endl;

	return 0;
}

