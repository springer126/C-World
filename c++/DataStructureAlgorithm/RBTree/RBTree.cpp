#include <iostream>
#include <iostream>  
#include <algorithm>  
#include <iterator>  
#include <vector>  
#include <sstream>  
using namespace std;

template <class KEY,class U>
class RB_TREE
{	
private:
	enum COLOR{RED,BLACK};
	class RB_NODE
	{
	public:
		RB_NODE()
		{
			right = NULL;
			left = NULL;
			parent = NULL;
		}
		KEY key;
		U value;
		COLOR color;
		RB_NODE *right;
		RB_NODE *left;
		RB_NODE *parent;
	};
private:
	RB_TREE(const RB_TREE &tree){}
	const RB_TREE& operator=(const RB_TREE &tree){}
	RB_NODE *m_nullNode;
	RB_NODE *m_root;
public:
	RB_TREE()
	{
		m_nullNode = new RB_NODE();
		m_root = m_nullNode;
		m_nullNode->color = BLACK;
		m_nullNode->right = m_root;
		m_nullNode->left = m_root;
		m_nullNode->parent = m_root;
	}
	
	bool Empty()
	{
		return m_root==m_nullNode;
	}
	
	RB_NODE* Find(KEY k)
	{
		RB_NODE *node = m_root;
		while(node!=m_nullNode)
		{
			if(k > node->key)
				node = node->left;
			else if(k<node->key)
				node = node->right;
			else
				break;
		}
		return node;
	}
	
	bool Insert(KEY k,U data)
	{
		RB_NODE *index = m_root;
		RB_NODE *insert_node = m_nullNode;
		while(index!=m_nullNode)
		{
			insert_node = index;
			if(index->key == k)
				return false;
			else if(k>index->key)
				index = index->right;
			else
				index  = index->left;
		}
		
		RB_NODE *node = new RB_NODE();
		node->key = k;
		node->value = data;
		node->color = RED;
		node->right = node->left = m_nullNode;
		
		if(Empty())
		{
			m_root = node;
			m_root->parent = m_nullNode;
			m_nullNode->right = m_nullNode->left = m_root;
			m_nullNode->parent = m_root;
		}
		else
		{
			if(insert_node->key > k)
				insert_node->right = node;
			else
				insert_node->left = node;
			
			node->left = node->right = m_nullNode;
			node->parent = insert_node;
		}
		InsertFixUp(node);
		return true;
	}
	
	void InsertFixUp(RB_NODE *node)
	{
		if(node == m_root)
			return;
		else if(node->parent->color == BLACK)
			return;
		else
		{
			while(node->parent->color==RED)//parent node is red
			{
				if(node->parent->parent->left == node->parent)
				{
					RB_NODE *uncle = node->parent->parent->right;
					if(uncle->color == RED)
					{
						uncle->color = BLACK;
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						node = node->parent->parent;
					}
					else if(uncle->color == BLACK)
					{
						if(node == node->parent->right)
						{
							node = node->parent;
							RotateLeft(node);
						}
						else if(node == node->parent->left)
						{
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							RotateRight(node->parent->parent);
						} 
					}
				}
				else
				{
					RB_NODE *uncle = node->parent->parent->left;
					if(uncle->color == RED)
					{
						uncle->color = BLACK;
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						node = node->parent->parent;
					}
					else if(uncle->color == BLACK)
					{
						if(node == node->parent->left)
						{
							node = node->parent;
							RotateRight(node);
						}
						else if(node == node->parent->right)
						{
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							RotateLeft(node->parent->parent);
						} 
					}
				}
			}
		}
		m_root->color = BLACK;
	}

	bool RotateLeft(RB_NODE *node)
	{
		if(node==m_nullNode || node->right==m_nullNode)
			return false;
		RB_NODE *lower_right = node->right;
		lower_right->parent = node->parent;
		node->right = lower_right->left;
		if(lower_right->left!=m_nullNode)
			lower_right->left->parent = node;
			
		if(node->parent==m_nullNode)
		{
			m_root = lower_right;
			m_nullNode->right = m_nullNode->left = m_root;
		}
		else
		{
			if(node->parent->left ==node)
				node->parent->left = lower_right;
			else
				node->parent->right = lower_right;
		}
		node->parent = lower_right;
		lower_right->left = node;
		return true;
	}
	
	bool RotateRight(RB_NODE *node)
	{
		if(node==m_nullNode || node->left==m_nullNode)
			return false;
		RB_NODE *lower_left = node->left;
		lower_left->parent = node->parent;
		node->left = lower_left->right;
		if(lower_left->right!=m_nullNode)
			lower_left->right->parent = node;
			
		if(node->parent==m_nullNode)
		{
			m_root = lower_left;
			m_nullNode->right = m_nullNode->left = m_root;
		}
		else
		{
			if(node->parent->left ==node)
				node->parent->left = lower_left;
			else
				node->parent->right = lower_left;
		}
		node->parent = lower_left;
		lower_left->right = node;
		return true;
	}
	
	bool Delete(KEY k)
	{
		RB_NODE *node;
		if((node=Find(k))== m_nullNode)
			return false;
		
		if(node->left !=m_nullNode && node->right!=m_nullNode)
		{
			RB_NODE *successor = InOrderSuccessor(node);
			node->value = successor->value;
			node->key = successor->key;
			node = successor;
		}
		
		RB_NODE *child;
		if(node->right !=m_nullNode)
		{
			child = node->right;
		}
		else if(node->left !=m_nullNode)
		{
			child = node->left;
		}
		else
		{
			child = m_nullNode;
		}
		
		child->parent = node->parent;
		if(node->parent == m_nullNode)
		{
			m_root = child;
			m_nullNode->left = m_nullNode->right = m_nullNode->parent = m_root;
		}
		else if(node == node->parent->left)
			node->parent->left = child;
		else
			node->parent->right = child;
		
		if(node->color==BLACK && !(child==m_nullNode && child->parent==m_nullNode))
			DeleteFixUp(child);
		delete node;
		return true;
	}
	
	 void DeleteFixUp(RB_NODE* node)  
	 {  
		while(node!=m_root && node->color==BLACK)  
		{  
			if(node == node->parent->left)  
			{  
				RB_NODE* brother = node->parent->right;  
				if(brother->color==RED)   //情况1：x的兄弟w是红色的。  
				{  
					brother->color = BLACK;  
					node->parent->color = RED;  
					RotateLeft(node->parent);  
				}  
				else     //情况2：x的兄弟w是黑色的，  
				{  
					if(brother->left->color == BLACK && brother->right->color == BLACK)  
						//且w的俩个孩子都是黑色的。  
					{  
						brother->color = RED;  
						node = node->parent;  
					}  
					else if(brother->right->color == BLACK)  
						//情况3：x的兄弟w是黑色的，w的右孩子是黑色（w的左孩子是红色）。  
					{  
						brother->color = RED;  
						brother->left->color = BLACK;  
						RotateRight(brother);  
					}  
					else if(brother->right->color == RED)  
						//情况4：x的兄弟w是黑色的，且w的右孩子时红色的。  
					{  
						brother->color = node->parent->color;  
						node->parent->color = BLACK;  
						brother->right->color = BLACK;  
						RotateLeft(node->parent);  
						node = m_root;  
					}  
				}  
			}  
			else  //下述情况针对上面的情况1中，node作为右孩子而阐述的。  
				//22        else (same as then clause with "right" and "left" exchanged)  
				//同样，原理一致，只是遇到左旋改为右旋，遇到右旋改为左旋，即可。其它代码不变。  
			{  
				RB_NODE* brother = node->parent->left;  
				if(brother->color == RED)  
				{  
					brother->color = BLACK;  
					node->parent->color = RED;  
					RotateRight(node->parent);  
				}  
				else  
				{  
					if(brother->left->color==BLACK && brother->right->color == BLACK)  
					{  
						brother->color = RED;  
						node = node->parent;  
					}  
					else if(brother->left->color==BLACK)  
					{  
						brother->color = RED;  
						brother->right->color = BLACK;  
						RotateLeft(brother);  
					}  
					else if(brother->left->color==RED)  
					{  
						brother->color = node->parent->color;  
						node->parent->color = BLACK;  
						brother->left->color = BLACK;  
						RotateRight(node->parent);  
						node = m_root;  
					}  
				}  
			}  
		}  
		m_nullNode->parent = m_root;   //最后将node置为根结点，  
		node->color = BLACK;    //并改为黑色。  
	 }  
		  
	//  
	inline RB_NODE* InOrderPredecessor(RB_NODE* node)  
	{  
		if(node==m_nullNode)       //null node has no predecessor  
		{  
			return m_nullNode;  
		}  
		RB_NODE* result = node->left;     //get node's left child  
		while(result!=m_nullNode)         //try to find node's left subtree's right most node  
		{  
			if(result->right!=m_nullNode)       
			{  
				result = result->right;  
			}  
			else  
			{  
				break;  
			}  
		}            //after while loop result==null or result's right child is null  
		if(result==m_nullNode)  
		{  
			RB_NODE* index = node->parent;  
			result = node;  
			while(index!=m_nullNode && result == index->left)  
			{  
				result = index;  
				index = index->parent;  
			}  
			result = index;         // first right parent or null  
		}  
		return result;  
	}  
	  
	//  
	inline RB_NODE* InOrderSuccessor(RB_NODE* node)  
	{  
		if(node==m_nullNode)       //null node has no successor  
		{  
			return m_nullNode;  
		}  
		RB_NODE* result = node->right;   //get node's right node  
		while(result!=m_nullNode)        //try to find node's right subtree's left most node  
		{  
			if(result->left!=m_nullNode)       
			{  
				result = result->left;  
			}  
			else  
			{  
				break;  
			}  
		}                              //after while loop result==null or result's left child is null  
		if(result == m_nullNode)  
		{  
			RB_NODE* index = node->parent;  
			result = node;  
			while(index!=m_nullNode && result == index->right)  
			{  
				result = index;  
				index = index->parent;  
			}  
			result = index;         //first parent's left or null  
		} return result;  
	}  
	  
	//debug  
	void InOrderTraverse()  
	{  
		InOrderTraverse(m_root);  
	}  
	void CreateGraph(string filename)  
	{  
		//delete  
	}  
	void InOrderCreate(ofstream& file,RB_NODE* node)  
	{  
		//delete  
	}  
	void InOrderTraverse(RB_NODE* node)  
	{  
		if(node==m_nullNode)  
		{  
			return;  
		}  
		else  
		{  
			InOrderTraverse(node->left);  
			cout<<node->key<<endl;  
			InOrderTraverse(node->right);  
		}  
	}  
	~RB_TREE()  
	{  
		clear(m_root);  
		delete m_nullNode;  
	}  
	
private:
	 void clear(RB_NODE* node)  
        {  
            if(node==m_nullNode)  
            {  
                return ;  
            }  
            else  
            {  
                clear(node->left);  
                clear(node->right);  
                delete node;  
            }  
        }  
};



using namespace std;  
  
int main()  
{  
    RB_TREE<int,int> tree;  
    vector<int> v;  
      
    for(int i=0;i<20;++i)  
    {  
        v.push_back(i);  
    }  
    random_shuffle(v.begin(),v.end());  
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));  
    cout<<endl;  
    stringstream sstr;  
    //int i;
    vector<int>::size_type i;
    for(i=0;i<v.size();++i)  
    {  
        tree.Insert(v[i],i);  
        cout<<"insert:"<<v[i]<<endl;   //添加结点  
    }  
    for(i=0;i<v.size();++i)  
    {  
        cout<<"Delete:"<<v[i]<<endl;  
        tree.Delete(v[i]);             //删除结点  
        tree.InOrderTraverse();  
    }  
    cout<<endl;  
    tree.InOrderTraverse();  
    return 0;  
}  
