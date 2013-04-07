// DijkstraShortestPath.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> // for std::cout
#include <utility> // for std::pair
#include <algorithm> // for std::for_each
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>

#include <tr1/random>

using namespace boost;
using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{
	typedef adjacency_list<listS, vecS, directedS, 
		no_property, property<edge_weight_t, int> > Graph;
	typedef graph_traits<Graph>::vertex_descriptor Vertex;
	typedef property_map<Graph,vertex_index_t>::type IndexMap;
	
	typedef std::pair<int,int> E;

	const int num_nodes = 5;
	E edges[] = { 
		E(0,2), E(1,1), E(1,3), E(1,4),
		E(2,1), E(2,3), E(3,4),E(4,0), E(4,1) };
	int weights[] = { 1, 2, 1, 2, 7, 3, 1, 1, 1};

	Graph g(edges,edges+sizeof(edges)/sizeof(E),weights,num_nodes);
	IndexMap index = get(vertex_index,g);

	std::vector<int> d(num_vertices(g));
	Vertex v = *(vertices(g).first);
	dijkstra_shortest_paths(g,v,distance_map(&d[0]));
	std::cout << "distance from start vertex v:"<< std::endl;
	graph_traits<Graph>::vertex_iterator vi;
	for (vi = vertices(g).first;vi!=vertices(g).second;vi++)
	{
		std::cout << "distance:("<<index[*vi]<<")="<<d[*vi]<<std::endl;
	}
	std::cout << std::endl;


	//std::iterator_traits<string *> 
	std::cout << std::numeric_limits<int>::max() << std::endl;
	std::tr1
	return 0;
}

