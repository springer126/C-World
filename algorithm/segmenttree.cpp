/**
 *线段树 实现
 * 输入若干区间，求在区间中出现最多的节点和次数
 * 
 *
 */

#include <iostream>
#include <algorithm>
using namespace std;


int n = 0;

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

bool isLeaf(Node *p);

Node *createTree(int low,int high)
{
	Node *root = new Node(low,high,0);
	if(low!=high)
	{	
	    int mid = (low+high)>>1;
		root->left = createTree(low,mid);
		root->right = createTree(mid+1,high);
	}
	
	return root;
}


bool insert(int low,int high,Node *root)
{
	if(root == NULL || low>high || low>root->high || high < root->low || low<root->low || high>root->high)
		return false;

	int mid = (root->high+root->low)>>1;
	if(low == high)
	{
		if(isLeaf(root) && root->low==low)
		{
			root->count++;
		}
		else
		{
			if(low>mid)
				insert(low,low,root->right);
			else
				insert(low,low,root->left);
		}	
	}
	else
	{
		if(high<=mid)
		{		
			insert(low,high,root->left);
		}		
		else if(low>mid)
		{
			insert(low,high,root->right);
		}
		else
		{
			if(low==root->low && high == root->high)
				root->count++;
			insert(low,mid,root->left);
			insert(mid+1,high,root->right);
		}
	}
	return true;
	
}

bool isLeaf(Node *p)
{
	if(p!=NULL && (p->low == p->high))
		return true;
	else
		return false;
}

void preOrder(Node *root)
{
	if(root == NULL)
		return ;
	
	std::cout <<(++n)<<" : ["<<root->low<<","<< root->high<<"]"<<",count = "<<root->count<<std::endl;
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(Node *root)
{
	if(root == NULL)
		return ;
	
	inOrder(root->left);
	std::cout <<(++n)<<" : ["<<root->low<<","<< root->high<<"]"<<",count = "<<root->count <<std::endl;
	inOrder(root->right);
}

void delTree(Node *root)
{
	if(root==NULL)
	{
		return;
	}
	else
	{
		delTree(root->left);
		delTree(root->right);
		delete root;
	}
}

int main()
{
	Node *root = createTree(1,10);
	n = 0;
	inOrder(root);
	std::cout << "Please Input Segment:"<< std::endl;
	int x,y;	
	while(std::cin >>x>>y)
	{
		if(x>y)
		{
			std::cout << "Invalid Segment!"<<std::endl;
			break;
		}
		if(insert(x,y,root))
		{
			inOrder(root);
		}
	}
	
	delTree(root);
	return 0;
}
