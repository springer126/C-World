// graph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/properties.hpp>
#include <iostream>
#include <fstream>
#include <istream>
#include <utility>

using namespace std;
using namespace boost;

namespace std
{
	template <typename T>
	std::istream& operator >>(std::istream& in, std::pair<T, T>& p)
	{
		in >> p.first >> p.second;
		return in;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	typedef boost::property<boost::edge_weight_t, int> EdgeWeightProperty;

	typedef boost::property<boost::vertex_name_t, std::string> VertexNameProperty;
	typedef property<vertex_index2_t, int> VertexIndexProperty;
	typedef property<vertex_name_t,std::string, property<vertex_index2_t,int> > VertexProperty;

	boost::adjacency_list<> mygraph;
	add_edge(1, 2, mygraph);
	add_edge(1, 3, mygraph);
	add_edge(1, 4, mygraph);
	add_edge(2, 4, mygraph);
	
	typedef adjacency_list<vecS, vecS, undirectedS,
				VertexNameProperty, EdgeWeightProperty> Graph;
	

	
	
	std::cout << " boost graph " << std::endl;


	typedef adjacency_list<listS, vecS, directedS> file_dep_graph;
	std::ifstream file_in("file.dat");
	typedef graph_traits<file_dep_graph>::vertices_size_type size_type;
	size_type n_vertices;
	file_in >> n_vertices;
	std::istream_iterator<std::pair<size_type, size_type> > input_begin(file_in), input_end;
	file_dep_graph g(input_begin, input_end, n_vertices);
	//需要对operator >>进行重载

	

	system("pause");
	return 0;
}

