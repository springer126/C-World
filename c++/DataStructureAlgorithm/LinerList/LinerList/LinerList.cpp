#include "LinerList.h"

template <class T>
LinerList<T>::LinerList(int maxSize):MaxSize(maxSize),length(0)
{
	element = new T[MaxSize];
}

template <class T>
LinerList<T>::LinerList(const LinerList<T> &L)
{
	MaxSize = L.MaxSize;
	length = L.Length();
	element = new T[length];
	for(int i=0;i<length;i++)
	{
		L.Find(i,element[i]);
	}
}

template <class T>
bool LinerList<T>::Find(int k,T &t) const
{
	if(k<1 && k>length)
		return false;
	else
	{
		t = element[k-1];
		return true;
	}
}

template <class T>
int LinerList<T>::Search(const T& x) const
{
	for (int i=0;i<length;i++)
	{
		if(element[i]==x)
			return ++i;
	}
	return 0;
}

template <class T>
LinerList<T>& LinerList<T>::Delete(int k,T &x)
{
	if(Find(k,x))
	{
		for (int i=k;i<length;i++)
		{
			element[i-1] = element[i]
		}
		length--;
		return *this;
	}
	else
	{
		throw exception;
	}
}

template <class T>
LinerList<T>& LinerList<T>::Insert(int k,const T &x)
{
	if(k==0 || k>length) throw exception;
	if(length==MaxSize) throw exception;

	for(int i=length-i;i>=k;i--)
	{
		element[i+1] = element[i];
	}
	element[k] = x;
	length++;
	return *this;
}