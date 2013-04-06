#pragma once
#include <iostream>
using namespace std;

template <class T>
class Handle
{
public:
	Handle(T *p=0):ptr(p),use(new size_t(1)){}
	T& operator*();
	T* operator->();
	const T& operator*() const;
	const T* operator->() const;

	Handle(const Handle &h):ptr(h.ptr),use(h.use){*use++;}
	Handle& operator=(const Handle &h);
	~Handle()
	{
		rem_ref();
	}

private:
	T* ptr;
	std::size_t *use;
	void rem_ref()
	{
		if(--*use==0)
		{
			delete ptr;
			delete use;
		}
	}
};


template <class T>
inline Handle<T>& Handle<T>::operator=(const Handle<T> &h)
{
	++*h.use;
	rem_ref();
	ptr = h.ptr;
	use = h.use;
	return *this;
}

template <class T>
inline T& Handle<T>::operator*()
{
	if(ptr)
		return *ptr;
	throw std::runtime_error("dereference of unbound Handle");
}

template <class T>
inline T* Handle<T>::operator->()
{
	if(ptr)
		return ptr;
	throw std::runtime_error("access through unbound Handle");
}

template <class T>
inline const T& Handle<T>::operator*() const 
{
	if(ptr)
		return *ptr;
	throw std::runtime_error("dereference of unbound Handle");
}

template <class T>
inline const T* Handle<T>::operator->() const
{
	if(ptr)
		return ptr;
	throw std::runtime_error("access through unbound Handle");
}