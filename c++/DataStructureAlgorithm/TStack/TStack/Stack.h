#ifndef _STACK_H_
#define  _STACK_H_

#include <iostream>
#include <exception>

template <class T>
class Stack
{
public:
	Stack(int MaxStackSize = 10)
	{
		top = -1;
		MaxTop = MaxStackSize-1;
		stack = new T[MaxStackSize];
	}
	~Stack()
	{
		delete[] stack;
	}
	bool IsEmpty()
	{
		return top ==-1;
	}
	bool IsFull()
	{
		return top == MaxTop;
	}

	T Top()
	{
		if (IsEmpty())
		{
			throw new std::exception;
		}
		return stack[top];
	}

	Stack& Add(const T &t)
	{
		if (IsFull())
		{
			return *this;
		}
		else
		{
			stack[++top] = t;
		}
		return *this;
	}

	Stack& Delete()
	{
		if (!IsEmpty())
		{
			top --;
		}
		return *this;
	}

private:
	int top;
	int MaxTop;
	T *stack;
};

template <class T>
class LinkStack;

template <class T>
class Node
{
    friend LinkStack<T>;
private:
	T data;
	Node *next;
};

template <class T>
class LinkStack
{
public:
	LinkStack()
	{
		top = 0;
	}
	~LinkStack()
	{
		Node<T> *temp;
		while (top)
		{
			temp = top->next;
			delete top;
			top = temp;
		}
	}
	bool IsEmpty()
	{
		return top ==0;
	}
	
	T Top()
	{
		if (IsEmpty())
		{
			throw new std::exception;
		}
		return top->data;
	}

	LinkStack& Add(const T &t)
	{
		Node<T> *temp = new Node<T>;
		temp->data = t;
		temp->next = top;
		top = temp;
		return *this;
	}

	LinkStack& Delete()
	{
		if (!IsEmpty())
		{
			Node<T> *temp;
			temp = top->next;
			delete top;
			top = temp;
		}
		return *this;
	}

private:
	Node<T> *top;
};
#endif