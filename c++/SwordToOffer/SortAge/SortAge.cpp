// SortAge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <stdlib.h>
#include <time.h>
int *age;
const int size = 100;

void sort(int age[],int length)
{
	if(age==NULL || length<=0)
		return;

	const int oldestAge = 99;
	int timeOfAge[oldestAge+1];
	memset(timeOfAge,0,sizeof(timeOfAge));
	for (int i=0;i<length;i++)
	{
		if(age[i]>oldestAge || age[i]<0)
			throw new std::exception("out of age range!");
		timeOfAge[age[i]]++;
	}

	int index = 0;
	for (int i=0;i<=oldestAge;i++)
	{
		for (int j=0;j<timeOfAge[i];j++)
		{
			age[index] = i;
			index++;
		}
	}
}

void build()
{
	srand(time(NULL));
	age = (int *)malloc(size*sizeof(int));
	for (int i=0;i<size;i++)
	{
		age[i] = rand()%100;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	
	build();
	sort(age,size);
	for(int i=0;i<size;i++)
	{
		std::cout << age[i] << std::endl;
	}
	
	if(age!=NULL)
		free(age);
	return 0;
}

