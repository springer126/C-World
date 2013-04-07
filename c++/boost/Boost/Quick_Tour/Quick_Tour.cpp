// Quick_Tour.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>                  // for std::cout
#include <utility>                   // for std::pair
#include <algorithm>                 // forstd::for_each
#include <math.h>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/graph_utility.hpp>
#include <boost/tuple/tuple.hpp>

#include <cstdlib>
#include <stdlib.h>
#include <boost/regex.hpp>
#include <string>


boost::regex expression("^select ([a-zA-Z]*) from ([a-zA-Z]*);");

using namespace std;
using namespace boost;

template <class Graph> 
struct exercise_vertex
{
	typedef typename boost::graph_traits<Graph>::vertex_descriptor Vertex;
	exercise_vertex(Graph& g_) : g(g_) {}
	Graph& g;
	void operator()(const Vertex& v) const
	{
		typedef graph_traits<Graph> GraphTraits;
		typename property_map<Graph, vertex_index_t>::type 
			index = get(vertex_index, g);

		std::cout << "out-edges: ";
		typename GraphTraits::out_edge_iterator out_i, out_end;
		typename GraphTraits::edge_descriptor e;
		for (boost::tie(out_i, out_end) = out_edges(v, g); 
			out_i != out_end; ++out_i) {
				e = *out_i;
				Vertex src = source(e, g), targ = target(e, g);
				std::cout << "(" << index[src] << "," 
					<< index[targ] << ") ";
		}
		std::cout << std::endl;

		std::cout << "in-edges: ";
		typename GraphTraits::in_edge_iterator in_i, in_end;
		for (tie(in_i, in_end) = in_edges(v,g); 
			in_i != in_end; ++in_i) {
				e = *in_i;
				Vertex src = source(e, g), targ = target(e, g);
				std::cout << "(" << index[src] << "," << index[targ] << ") ";
		}
		std::cout << std::endl;

		std::cout << "adjacent vertexs:";
		typename GraphTraits::adjacency_iterator ad_i,ad_end;
		for(tie(ad_i,ad_end) = adjacent_vertices(v,g);ad_i!=ad_end;ad_i++)
		{
			std::cout <<" "<< index[*ad_i];	
		}
		std::cout << std::endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
	using namespace boost;
	typedef adjacency_list<vecS,vecS,bidirectionalS> Graph;
	enum{A,B,C,D,E,N};
	const int num_vertiaces = N;
	const char *name = "ABCDE";
	const char *name1 = "12345";

	typedef pair<int,int> Edge;
	Edge edge_array[]  = {
		Edge(A,B),Edge(A,D), Edge(C,A), Edge(D,C),Edge(C,E), Edge(B,D), Edge(D,E)
	};
	const int num_edges = sizeof(edge_array)/sizeof(edge_array[0]);
	Graph g(num_vertiaces);

	// 给图对象增加边
	for (int i = 0; i < num_edges; ++i)
		add_edge(edge_array[i].first, edge_array[i].second, g);

	boost::print_graph(g);
	boost::print_edges(g,name);
	boost::print_vertices(g,name1);
    

	std::cout << "======================================"<< std::endl;
	typedef property_map<Graph, vertex_index_t>::type IndexMap;
	typedef property_map<Graph, vertex_name_t>::type VertexNameMap;;
	typedef property_map<Graph, vertex_out_degree_t>::type VertexOutDegreeMap;
	typedef property_map<Graph, vertex_color_t>::type VertexColorMap;
	typedef property_map<Graph, edge_name_t>::type EdgeNameMap;
	typedef property_map<Graph, edge_weight_t>::type EdgeWeightMap;
	typedef property_map<Graph, edge_capacity_t>::type EdgeCapacityMap;

	IndexMap index = get(vertex_index, g);
	VertexNameMap v_name = get(vertex_name,g);
	VertexOutDegreeMap v_out_degree = get(vertex_out_degree,g);
	std::cout << "vertices(g) = ";
	typedef graph_traits<Graph>::vertex_iterator vertex_iter;

	std::pair<vertex_iter, vertex_iter> vp;
	for (vp = vertices(g); vp.first != vp.second; ++vp.first)
	{
		std::cout <<" "<<index[*vp.first] ;
	}
	std::cout << std::endl;

	graph_traits<Graph>::edge_iterator ei, ei_end;
	for (tie(ei, ei_end) = edges(g); ei != ei_end; ++ei)
		std::cout << "(" << index[source(*ei, g)] 
	<< "," << index[target(*ei, g)] << ") ";
	std::cout << std::endl;

	cout << "====================================" <<endl;
	std::for_each(vertices(g).first,vertices(g).second,exercise_vertex<Graph>(g));



	//test regex
	std::string in;
	cmatch what;
	cout << "enter test string" << endl;
	getline(cin,in);
	if(regex_match(in.c_str(), what, expression))
	{
		for(int i=0;i<what.size();i++)
			cout<<"str :"<<what[i].str()<<endl;
	}
	else
	{
		cout<<"Error Input"<<endl;
	}
	return 0;
}
