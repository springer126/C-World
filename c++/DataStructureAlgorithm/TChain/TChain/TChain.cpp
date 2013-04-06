// TChain.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Chain.h"
#include <string>
#include <math.h>
/**student information node**/
class Node
{
friend ostream& operator<<(ostream &out,const Node &node);
public:
	Node():name(),score(0){}
	Node(string sname,int sscore):name(sname),score(sscore){}
	int operator!=(const Node &node)const
	{
		return (this->score!=int(node));
	}
	operator int()const
	{
		return score;
	}
private:
	int score;
	string name;
};

ostream& operator<<(ostream &out,const Node &node)
{
	out << node.name << " " << node.score << std::endl;
	return out;
}

void BinSort(Chain<Node> &list,int range)
{
	int length = list.Length();
	Node x;
	Chain<Node> *bin;
	bin = new Chain<Node>[range+1];
	for (int i=1;i<=length;i++)
	{
		list.Delete(1,x);
		bin[int(x)].Insert(0,x);
	}

	for (int j=range;j>=0;j--)
	{
		while(!bin[j].IsEmpty())
		{
			bin[j].Delete(1,x);
			list.Insert(0,x);
		}
	}

	delete[] bin;
}


int _tmain(int argc, _TCHAR* argv[])
{
	Chain<int> chain;
	chain.Insert(1,1);
	chain.Insert(2,6);
	chain.Insert(3,2);
	chain.Insert(4,8);
	std::cout << chain << std::endl;

	int x;
	chain.Delete(2,x);
	std::cout << chain << std::endl;
	
	Chain<int> cc;
	for (int k=1;k<100;k++)
	{
		cc.Insert(k,k);
	}
	std::cout << cc << std::endl;
	for (int k=1;k<20;k++)
	{
		cc.Delete(k,x);
	}
	std::cout << cc << std::endl;

	Chain<Node> stuList;
	for (int k=1;k<100;k++)
	{
		int random = rand()%100+1;
		Node node("wenhui",random);
		stuList.Insert(k,node);

	}
	std::cout << stuList << std::endl;
	BinSort(stuList,100);
	std::cout << stuList << std::endl;
	return 0;
}

