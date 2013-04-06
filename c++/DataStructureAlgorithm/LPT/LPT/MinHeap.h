#ifndef _MINHEAP_H_
#define  _MINHEAP_H_

#include <iostream>

template <class T>
class MinHeap
{
public:
	MinHeap():curSize(0),MaxSize(10){data = new T[MaxSize];}
	MinHeap(int size):curSize(0),MaxSize(size){data = new T[size];}
	virtual ~MinHeap(){if(data){delete[] data;}};
	int Size() const{return curSize;}
	void init(T *t,int len)
	{
		if(len>MaxSize)
			return;
		curSize = len;
		for (int i=0;i<len;i++)
			this->data[i] = t[i];

		for (int i=len/2;i>=1;i--)
		{
			while (i<=len/2)
			{
				int pos = i*2;
				T temp = data[i*2-1];
				if(i*2<len && data[i*2]<temp)
				{
					temp = data[i*2];
					pos = i*2+1;
				}
				if(temp<data[i-1])
				{
					data[pos-1] = data[i-1];
					data[i-1] = temp;	
					i = pos;
				}
				else
					break;
			}
			
		}
	}

	void printHeap()
	{
		std::cout << "==================" << std::endl;
		for (int i=0;i<curSize;i++)
		{
			std::cout << data[i] << std::endl;
		}
		std::cout << "==================" << std::endl;
	}

	void Min(T &t)
	{
		if(curSize>=1) 
			t = data[0];
	}

	void Insert(T &t)
	{
		if(curSize == MaxSize)
			return;
		data[curSize++] = t;
		int pos = curSize;
		while(pos>1)
		{
			T temp = t;
			if((data[pos/2-1])>(temp))
			{
				data[pos-1] = data[pos/2-1];
				data[pos/2-1] = temp;
			}
			pos = pos/2;
		}
	}

	void Delete(T &t)
	{
		if(curSize>1)
		{
			t = data[0];
			data[0] = data[curSize-1];
			data[curSize-1] = t;

			--curSize;
			int pos = 1;
			while(pos <= curSize/2)
			{
				T temp = data[pos*2-1];
				int i = pos*2;
				if(pos*2+1<=curSize && data[pos*2]<temp)
				{
					temp = data[pos*2];
					i = 2*pos+1;
				}
				if(temp<data[pos-1])
				{
					data[i-1] = data[pos-1];
					data[pos-1] = temp;
					pos = i;
				}
				else
					break;
			}
		}
		else if(curSize==1)
			t = data[0];
	}

private:
	T *data;
	int MaxSize;
	int curSize;
};


#endif
