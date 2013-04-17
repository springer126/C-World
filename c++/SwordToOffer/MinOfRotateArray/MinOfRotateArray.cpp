// MinOfRotateArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
const int size = 1000;

template <class T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <class T>
void reverse(T *arr,int start,int end)
{
	if(arr==NULL || start<0 ||end>=size ||  start==end)
		return;
	while(start<end)
	{
		swap(arr[start],arr[end]);
		start++;
		end--;
	}
}


template <class T>
void findMinOfRotateArr(T *arr,T &t,int length = size)
{
	int start = 0;
	int end = length-1;
	int middle;
	while(start+1!=end)
	{
		middle = (start+end)/2;
		if(arr[middle]>arr[start])
			start = middle;
		else if(arr[middle]<arr[end])
			end = middle;
	}

	t = arr[end];
}

int _tmain(int argc, _TCHAR* argv[])
{
	int arr[size];
	for (int i=0;i<size;i++)
	{
		arr[i] = i+4;
	}

	reverse(arr,0,10);
	reverse(arr,11,size-1);
	reverse(arr,0,size-1);
	for (int i=0;i<size;i++)
	{
		std::cout <<arr[i]<<" ";
		if(i%10==0)
			std::cout << std::endl;
	}
	std::cout << std::endl;

	int k;
	findMinOfRotateArr(arr,k);
	std::cout << " Min element: " << k <<std::endl;
	return 0;
}

