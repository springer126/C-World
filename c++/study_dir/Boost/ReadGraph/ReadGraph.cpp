//#pragma comment(lib,"libboost_graph-vc80-mt-1_38.lib")
#pragma comment(lib,"boost_graph-vc80-1_38.lib")

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphml.hpp>
#include <boost/graph/graph_utility.hpp>
#include <fstream>
#include <string>

using namespace std;
using namespace boost;

int main(int argc, char** argv)
{
	typedef boost::adjacency_list<vecS,vecS,directedS, 
		property<vertex_color_t,int,
		property<vertex_name_t,string> >,
		property<edge_weight_t,double> > graph_t;
	graph_t g;
	const char *name="ABCDEF";
	dynamic_properties dp;
	dp.property("foo",get(vertex_color_t(),g));
	dp.property("weight",get(edge_weight_t(),g));
	dp.property("name",get(vertex_name_t(),g));
	
	ifstream ifile("D:\\graphml_test_in.xml");
	try
	{
		boost::read_graphml(ifile, g, dp);
	}
	catch ( graph_exception& e)
	{
		std::cout << e.what() <<std::endl;
	}

	
	
	ifile.close();
	std::cout << num_vertices(g) << std::endl;
	boost::print_graph(g,name);
	cout << "====================================="<<endl;

	assert(num_vertices(g) == 9);
	assert(num_edges(g) == 9);
	assert(get(vertex_color_t(), g, vertex(2,g)) == 100);
	assert(get(vertex_color_t(), g, vertex(3,g)) == 42);
	assert(get(edge_weight_t(), g, edge(vertex(0,g),vertex(1,g),g).first) == 0.0);
	assert(get(edge_weight_t(), g, edge(vertex(1,g),vertex(2,g),g).first) == 0.8);

	ofstream ofile("D:\\graphml_test_out.xml");
	write_graphml(ofile, g, dp);
	ofile.close();

	graph_t g2;
	dynamic_properties dp2;
	dp2.property("foo",get(vertex_color_t(),g2));
	dp2.property("weight",get(edge_weight_t(),g2));
	dp2.property("name",get(vertex_name_t(),g2));
	ifile.open("D:\\graphml_test_out.xml");
	read_graphml(ifile, g2, dp2);
	ifile.close();

	assert(num_vertices(g) == num_vertices(g2));
	assert(num_edges(g) == num_edges(g2));

	graph_traits<graph_t>::vertex_iterator v, v_end;
	for (boost::tie(v,v_end) = vertices(g); v != v_end; ++v)
		assert(get(vertex_color_t(), g, *v) == get(vertex_color_t(), g2, *v));

	graph_traits<graph_t>::edge_iterator e, e_end;
	for (boost::tie(e,e_end) = edges(g); e != e_end; ++e)
		assert(get(edge_weight_t(), g, *e) == get(edge_weight_t(), g2, *e));

	return 0;
}
