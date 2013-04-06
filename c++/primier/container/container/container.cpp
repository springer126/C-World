// container.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <utility>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <list>
#include <fstream>
#include "TCompare.h"
using namespace std;


typedef vector<string>::size_type line_no;

class TextQuery
{

private:
	vector<string> lines_text;
	map< string , set<line_no> > word_map; 
public:

	TextQuery()
	{

	};
	
	~TextQuery()
	{

	};

	void read_file(ifstream &is)
	{
		string text_line;
		string word;
		while(getline(is,text_line))
		{
			lines_text.push_back(text_line);
		}

		//---------build map---------//
		for (line_no line_num = 0;line_num!=lines_text.size();line_num++)
		{
			//use istringstream to split words
			istringstream line(lines_text[line_num]);
			while (line >> word)
			{
				word_map[word].insert(line_num);
			}
		}
	}

	set<line_no> runQuery(const string &query_word) const
	{
		map<string,set<line_no> >::const_iterator loc = word_map.find(query_word);
		if (loc==word_map.end())
		{
			return set<line_no>();
		} 
		else
		{
			return loc->second;
		}
	}


	string text_line(line_no line) const
	{
		if(line<lines_text.size())
			return lines_text[line];
		throw std::out_of_range("line number out of range.");
	}

	void print_results(const set<line_no> &locs,const string &sought,const TextQuery &file)
	{
		typedef set<line_no> line_nums;
		line_nums::size_type size = locs.size();
		cout << "\n" << sought << " occurs " <<size<<": " <<endl;

		line_nums::const_iterator it = locs.begin();
		for (;it!=locs.end();++it)
		{
			cout <<"\t (line" << ((*it)+1)<< ")"<<file.text_line(*it)<<endl;
		}
	}

	void test()
	{
		for (line_no i = 0;i<lines_text.size();i++)
		{
			cout << lines_text[i] << endl;
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	/*
	string str;
	int val;
	pair<string,int> next_pair;
	vector< pair<string ,int> > vec;
	while(cin >> str >> val)
	{
		next_pair = make_pair(str,val);
		vec.push_back(next_pair);
	}

	for (vector< pair<string ,int> >::iterator beg = vec.begin(); beg!=vec.end(); beg++)
	{
		cout << beg->first << " " << beg->second << " "<<endl;
	}
	*/

	/*
	map<string,int> m;
	string str;
	while(cin >> str)
	{
		//m[str]++;//用下标访问不存在的元素将会增加新元素
		pair< map<string,int>::iterator,bool> ret = m.insert(make_pair(str,1));
		if(!ret.second)
		{
			++ret.first->second;		
		}
	}

	for (map<string,int>::iterator beg = m.begin(); beg!=m.end(); beg++)
	{
		cout << beg->first << " " << beg->second << " "<<endl;
	}
	*/
	
	std::list<int>::iterator beg;
	std::list<int> ilist,ilist1,ilist2;
	for (int i=0;i!=4;i++)
	{
		ilist.push_front(i);
	}
	for (beg = ilist.begin();beg!=ilist.end();beg++)
	{
		std::cout << *beg << " ";
	}
	copy(ilist.begin(),ilist.end(),front_inserter(ilist1));
	for (beg = ilist1.begin();beg!=ilist1.end();beg++)
	{
		std::cout << *beg << " ";
	}
	copy(ilist.begin(),ilist.end(),inserter(ilist2,ilist2.begin()));
	for (beg = ilist2.begin();beg!=ilist2.end();beg++)
	{
		std::cout << *beg << " ";
	}

	std::cout << compare(12,11) <<std::endl;

	TextQuery tq;
	string s;
	ifstream infile("E:\\text.txt");
	tq.read_file(infile);
	tq.test();
	while(cin >>s)
	{
		set<line_no> locs = tq.runQuery(s);
		tq.print_results(locs,s,tq);
	}
	


	return 0;
}

