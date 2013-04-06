#ifndef MyQueue_H
#define MyQueue_H

#include "MyQueueItem.h"

template <typename Type>
class MyQueue
{
public:
	MyQueue():head(0),tail(0){}
	MyQueue(const MyQueue &Q):head(0),tail(0)
	{
		copy_elems(Q);
	}
	MyQueue& operator=(const MyQueue& q)
	{
		while (!empty())	
		{
			pop();
		}

		while(!q.empty())
		{
			push(q.front());
			q.pop();
		}
	}

	~MyQueue()
	{
		destroy();
	}

	Type& front()
	{
		return head->item;
	}

	const Type& front()const
	{
		return head->item;
	}

	void push(const Type& item)
	{
		MyQueueItem<Type> *pt = new MyQueueItem<Type>(item);
		if(empty())
			head = tail = pt;
		else
		{
			tail->next = pt;
			tail=pt;
		}
	}

	void pop()
	{
		MyQueueItem<Type> *pt = head;
		head = head->next;
		delete pt;
	}

	bool empty() const
	{
		return head==0;
	}

	void destroy()
		{
			while (!empty())
			{
				pop();
			}
		}
		void copy_elems(const MyQueue& orig)
		{
			for (MyQueueItem<Type> *pt = orig.head;pt;pt= pt->next)
			{
				push(pt->item);
			}	
		}

private:
		typename MyQueueItem<Type>  *head;
		typename MyQueueItem<Type>  *tail;
		
};

#endif
