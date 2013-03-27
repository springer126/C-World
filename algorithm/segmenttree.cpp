/**
 *线段树 实现
 * 输入若干区间，求在区间中出现最多的节点和次数
 * 
 *
 */

#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
	int low;
	int high;
	int count; 			//区间覆盖次数
	struct node *left;
	struct node *right;

	node(int l,int h,int c)
	{
		low = l;
		high = h;
		count  = c;
		left = right = NULL;
	}
};


typedef struct node Node;

Node *createTree(int low,int high)
{
	Node *root = new Node;
	root->low = low;
	root->high = high;
	
}

int main(){}
