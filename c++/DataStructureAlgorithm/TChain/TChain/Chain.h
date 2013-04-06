#pragma once
#include <iostream>
using namespace std;

template <class T>
class Chain;

template <class T>
class ChainNode
{
	friend Chain<T>;
private:
	T data;
	ChainNode<T> *link;
};

template <class T>
class Chain
{
public:
	Chain(){first = 0;}
	~Chain(void)
	{
		ChainNode<T> *next;
		while(first)
		{
			next = first->link;
			delete first;
			first = next;
		}
	}
	bool IsEmpty(){return first==0;}
	int Length() const
	{
		int i=0;
		ChainNode<T> *next = first;
		while(next)
		{
			next = next->link;
			i++;
		}
		return i;
	}

	bool Find(int k,T &x)
	{
		if (k<1 || k>Length())
			return false;
		else
		{
			int index = 1;
			ChainNode<T> *current = first;
			while(index!=k && current)
			{
				index++;
				current = current->link;
			}
			x = current->data;
			return true;
		}
	}

	int Search(const T &x)const
	{
		ChainNode<T> *current = first;
		int index =1;
		while(current && current->data!=x)
		{
			current = current->link;
			index++;
		}
		if(current)
			return index;
		return 0;
	}

	Chain<T>& Delete(int k, T &x)
	{
		if(k<1 || !first)
		{
			throw new exception();
		}
		else
		{
			if(k==1)
			{
				x = first->data;
				first = first->link;		
			}
			else
			{
				int index = 1;
				ChainNode<T> *current = first;
				ChainNode<T> *p = first;
				while(current && index!=k)
				{
					index++;
					p = current;
					current = current->link;
				}
				p->link = current->link;
				x = current->data;
				delete current;
			}
			return *this;
		}
	}


	Chain<T>& Insert(int k,const T& x)
	{
		if(k<1 && k>Length())
			return *this;
		else
		{
			int index = 1;
			ChainNode<T> *current = first;
			ChainNode<T> *p = NULL;
			while (current && index!=k)
			{
				index++;
				p = current;
				current = current->link;
			}
			ChainNode<T> *node = new ChainNode<T>();
			node->data = x;
			node->link = current;
			if(p)
				p->link = node;
			else
			{
				first = node;	
			}
			return *this;
		}
	}

	void Output(ostream &out)const
	{
		ChainNode<T> *current;
		for (current=first;current;current=current->link)
		{
			out << current->data<< " "; 
		}
	}

	friend ostream& operator<< (ostream &out ,Chain<T> &x)
	{
		x.Output(out);
		return out;
	}

private:
	ChainNode<T> *first;
};
