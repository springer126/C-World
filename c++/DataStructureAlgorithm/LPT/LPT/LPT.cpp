// LPT.cpp : Defines the entry point for the console application.
// 最长处理时间优先

#include "stdafx.h"
#include "MinHeap.h"
#include <algorithm>

struct JobNode
{
	int id;
	int finishTime;
	operator int() const {return finishTime;}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int job[] = {2,9,3,8,4,0,6,1};
	int a[] = {0,0,0,0,0,0,0,0};
	int machines = 3;
	int k;

	MinHeap<JobNode> heap(4);
	JobNode node;
	for (int i=0;i<4;i++)
	{
		node.finishTime = 0;
		node.id = i+1;
		heap.Insert(node);
	}
	//heap.printHeap();
	std::sort(job,job+8);
	
	int time;
	for (int i=7;i>=0;i--)
	{
		heap.Delete(node);
		std::cout << "Schedule Job: "<< i+1 << " on machine "<< node.id << " from "<<node.finishTime << " to " << node.finishTime+job[i]<< std::endl;
		node.finishTime += job[i];
		heap.Insert(node);                                                                                                                                                                                                                     
	}

	
	return 0;
}

