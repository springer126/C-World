#ifndef _QUEUE_H_
#define  _QUEUE_H_
#include <iostream>

template <class T>
class Queue
{
public:
	Queue(int size=10):front(0),rear(0),MaxSize(size+1)
	{
		queue = new T[MaxSize];
	}
	~Queue()
	{
		delete[] queue;
	}
	bool IsEmpty() const
	{
		return front == rear;
	}

	bool IsFull() const
	{
		return (rear+1)%MaxSize == front;
	}

	T First() const
	{
		if(!IsEmpty())
			return queue[(front+1)%MaxSize];
	}

	T Last() const
	{
		if(!IsEmpty())
			return queue[rear];
	}

	Queue<T>& Add(const T &t)
	{
		if (!IsFull())
		{
			rear = (rear+1)%MaxSize;
			queue[rear] = t;
			return *this;
		}
	}

	Queue<T>& Delete(T &t)
	{
		if (!IsEmpty())
		{
			front = (front+1)%MaxSize;
			t = queue[front];
			return *this;
		}
	}

private:
	int front,rear;
	T *queue;
	int MaxSize;
};

#endif
