// PropertyMap.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "string"
#include <fstream>
#include <iosfwd>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphml.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/graph/graph_utility.hpp>

using namespace boost;
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	/*
	namespace boost {
		enum edge_flow_t { edge_flow };
		enum edge_capacity_t { edge_capacity };

		BOOST_INSTALL_PROPERTY(edge, flow);
		BOOST_INSTALL_PROPERTY(edge, capacity);
	}

	typedef property<edge_capacity_t, int> Cap;
	typedef property<edge_flow_t, int, Cap> EdgeProperty;
	typedef adjacency_list<vecS, vecS, no_property, EdgeProperty> Graph;
	
	property_map<Graph, edge_capacity_t>::type capacity = get(edge_capacity(), G);
	property_map<Graph, edge_flow_t>::type flow = get(edge_flow(), G);*/


	typedef adjacency_list<vecS,vecS,directedS,
		property<vertex_name_t,std::string> >grapht;
	
	/*
	grapht g,g_t;
	graph_traits<grapht>::vertex_descriptor u =add_vertex(g);
	graph_traits<grapht>::vertex_descriptor v =add_vertex(g);
	property_map<grapht,vertex_name_t>::type
		namemap=get(vertex_name,g);
	namemap[u] ="Joe";
	namemap[v] = "Kate";
	add_edge(u,v,g);
	std::cout <<namemap[u]<<std::endl;
	std::cout <<namemap[v]<<std::endl;

	dynamic_properties dp;
	dp.property("name",get(vertex_name_t(),g));
	std::ofstream ofile("D:\\graphml_test_out.xml");
	write_graphml(ofile, g, dp);
	ofile.close();
	*/

	grapht g_t;
	dynamic_properties dp;
	dp.property("name",get(vertex_name_t(),g_t));
	std::ifstream infile("D:\\graphml_test_out.xml");

		
	try
	{
		read_graphml(infile, g_t,dp);
	}
	catch (parse_error &e)
	{
		std::cout << e.what()<< std::endl;
	}
	
	
	infile.close();
	std::cout << "1" << std::endl;
	property_map<grapht,vertex_name_t>::type
		namemap0=get(vertex_name,g_t);
	graph_traits<grapht>::vertex_iterator i,end;
	for(tie(i,end) = vertices(g_t);i!=end;i++)
	{
		std::cout << namemap0[*i] << std::endl;
	}
	return EXIT_SUCCESS;
}

