#pragma once

#include <iostream>
#include <exception>
using namespace std;

template <class T>
class LinerList
{
private:
	int length;
	int MaxSize;
	T *element;
public:
	LinerList(int maxSize =10)
	{
		length = 0;
		MaxSize = maxSize;
		element = new T[maxSize];
	}
	
	LinerList(const LinerList<T> &L)
	{
		length = L.Length();
		MaxSize = L.MaxSize;
		element = new T[length];
		for (int i=1;i<=length;i++)
		{
			L.Find(i,element[i-1]);
		}
	}

	~LinerList()
	{
		delete []element;
	}

	bool IsEmpty() const
	{
		return length ==0;
	}
	
	int Length() const
	{
		return length;
	}

	bool Find(int k,T &x) const
	{
		if(k<1 && k>length)
			return false;
		else
		{
			x = element[k-1];
			return true;
		}
	}

	int Search(const T& x) const
	{
		for (int i=0;i<length;i++)
		{
			if(element[i]==x)
				return ++i;
		}
		return 0;
	}

	LinerList<T>& Delete(int k,T &x)
	{
		if(Find(k,x))
		{
			for (int i=k;i<length;i++)
			{
				element[i-1] = element[i];
			}
			length--;
			return *this;
		}
		else
		{
			throw new exception();
		}
	}

	LinerList<T>& Insert(int k,const T &x)
	{
		if(k<0 || k>length) throw new exception();
		if(length==MaxSize) throw new exception();

		for(int i=length-2;i>=k;i--)
		{
			element[i+1] = element[i];
		}
		element[k] = x;
		length++;
		return *this;
	}

	LinerList<T>& Half()
	{
		T t;
		for(int i=length;i>=1;i--)
		{
			Delete(i,t);	
			i--;
		}
		return *this;
	}

	void Output(std::ostream &out) const
	{
		for (int i=0;i<length;i++)
		{
			out << element[i]<<",";
		}
	}

	friend std::ostream& operator <<(std::ostream &out,const LinerList<T> &t)
	{
		t.Output(out);
		return out;
	}
};
