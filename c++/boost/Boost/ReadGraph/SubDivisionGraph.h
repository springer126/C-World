#ifndef _SUBDIVISIONGRAPH_
#define _SUBDIVISIONGRAPH_
#include <iostream>
#include <string>
#include <fstream>
#include <wchar.h>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphml.hpp>

class SubDivisionGraph
{
public:
	struct vertex_Xcoordinate_t {
		typedef boost::vertex_property_tag kind;
	};
	struct vertex_Ycoordinate_t {
		typedef boost::vertex_property_tag kind;
	};
	struct vertex_Zcoordinate_t {
		typedef boost::vertex_property_tag kind;
	};
	struct vertex_radius_t {
		typedef boost::vertex_property_tag kind;
	};
	
	struct edge_meanradius_t {
		typedef boost::edge_property_tag kind;
	};
	struct edge_distance_t {
		typedef boost::edge_property_tag kind;
	};
	struct edge_length_t {
		typedef boost::edge_property_tag kind;
	};	

	struct edge_treeno_t {
		typedef boost::edge_property_tag kind;
	};
	
	struct edge_angle_t {
		typedef boost::edge_property_tag kind;
	};


	typedef boost::property<vertex_Xcoordinate_t, double> XCoordProperty;
	typedef boost::property<vertex_Ycoordinate_t,double, XCoordProperty> XYCoordProperty;
	typedef boost::property<vertex_Zcoordinate_t,double, XYCoordProperty> XYZCoordProperty;
	typedef boost::property<vertex_radius_t,double, XYZCoordProperty> VertexProperty;
	typedef boost::property<edge_meanradius_t, double> MeanrProperty;
	typedef boost::property<edge_distance_t,double, MeanrProperty> DisProperty;
	typedef boost::property<edge_length_t,double, DisProperty> LengthProperty;
	typedef boost::property<edge_treeno_t,int, LengthProperty> TreenoProperty;
	typedef boost::property<edge_angle_t,double, TreenoProperty> EdgeProperty;

	typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::bidirectionalS, VertexProperty, EdgeProperty> Graph; 
	Graph dg, g;

	void ReadFromFile(const wchar_t *Path,Graph gra );
	void SaveToFile( const wchar_t * Path, Graph gra );
	void PrintVertexs();
};
#endif

