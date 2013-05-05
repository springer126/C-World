#ifndef _H_MYQUEUE_
#define _H_MYQUEUE_

#pragma once

#include <stack>

template <class T>
class CMyQueue
{
public:		
	CMyQueue(){}
	void append(const T& t)
	{
		stack1.push(t);
	}


	T del(){
		if(stack2.empty())
		{
			if(stack1.size()<=0)
				throw new std::exception("empty queue");
			else
			{
				while(!stack1.empty())
				{
					stack2.push(stack1.top());
					stack1.pop();
				}
			}

		}

		T t= stack2.top();
		stack2.pop();

		return t;
	}

public:
	virtual ~CMyQueue(){}

private:
	std::stack<T> stack1;
	std::stack<T> stack2;
};

#endif

