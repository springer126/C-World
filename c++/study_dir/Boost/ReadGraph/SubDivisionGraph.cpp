#include "SubDivisionGraph.h"
#include <boost/graph/graphml.hpp>
#include <boost/tuple/tuple.hpp>
#include <iostream>
#include <math.h> 
using namespace std;
using namespace boost;

void SubDivisionGraph::SaveToFile( const wchar_t * Path, Graph gra )
{
	std::ofstream out;
	out.open( Path, std::ios::out );
	/** Write graphml */
	boost::dynamic_properties dp;
	dp.property("XCoord", get(vertex_Xcoordinate_t(), gra));
	dp.property("YCoord", get(vertex_Ycoordinate_t(), gra));
	dp.property("ZCoord", get(vertex_Zcoordinate_t(), gra));
	dp.property("Radius", get(vertex_radius_t(), gra));
	dp.property("MeanRadius", get(edge_meanradius_t(), gra));
	dp.property("Distance", get(edge_distance_t(), gra));
	dp.property("Length", get(edge_length_t(), gra));	
	dp.property("Treeno", get(edge_treeno_t(), gra));
	dp.property("Angle", get(edge_angle_t(), gra));
	write_graphml(out, gra, dp, true); 
	return;
}

void SubDivisionGraph::ReadFromFile(const wchar_t *Path,Graph g )
{
	std::ifstream inputFile(Path);

	/** Read graphml */
	boost::dynamic_properties dp;
	dp.property("XCoord", get(vertex_Xcoordinate_t(), g));
	dp.property("YCoord", get(vertex_Ycoordinate_t(), g));
	dp.property("ZCoord", get(vertex_Zcoordinate_t(), g));
	dp.property("Radius", get(vertex_radius_t(), g));
	dp.property("MeanRadius", get(edge_meanradius_t(), g));
	dp.property("Distance", get(edge_distance_t(), g));
	dp.property("Length", get(edge_length_t(), g));	
	dp.property("Treeno", get(edge_treeno_t(), g));
	dp.property("Angle", get(edge_angle_t(), g));
	
	try
	{
		//read_graphml(inputFile, g, dp); 
	}
	catch (std::exception e)
	{
		cout << e.what()<<endl;
	}
	
	inputFile.close();
	return;
}

void SubDivisionGraph::PrintVertexs()
{
	graph_traits< Graph >::vertex_iterator i,end;
    property_map<Graph,vertex_index_t>::type index_map = get(vertex_index,g);
	for (tie(i,end) = vertices(g);i!=end;i++)
	{
		std::cout << get(index_map,*i)<< std::endl;
	}
}