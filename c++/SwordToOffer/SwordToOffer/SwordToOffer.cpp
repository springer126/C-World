// SwordToOffer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <limits.h>
#include <string.h>
#include <time.h>
#include <fstream>
#include <iostream>


struct LinkNode 
{
	int value;
	LinkNode *next;
};

bool Increment(char *number)
{
	bool isOverflow = false;
	int length = strlen(number);
	int k = length-1;
	number[k]+=1;
	while(number[k]-'9'>0)
	{
		if((k-1)>=0)
		{
			number[k-1]+=1;
			number[k]='0';
			k--;
		}
		else
			return false;
	}
	return true;
}

void print1ToMaxOfNDigits(int n)
{
	if(n<=0)
		return;

	char *number = new char[n+1];
	memset(number,'0',n);
	number[n] = '\0';

	while(Increment(number))
	{
		char *name = number;
		while (*name=='0')
		{
			name++;
		}
		printf("%s\n",name);
	}

	delete[] number;
}


void ReorderOddEven(int *pData,unsigned int length,bool (* pFunc)(int))
{
	if(length<=0 || pData==NULL)
		return;

	int *head = pData;
	int *tail = pData+length-1;
	while (head<tail)
	{
		while (head<tail && !pFunc(*head))
		{
			head++;
		}
		while (head<tail && pFunc(*tail))
		{
			tail--;
		}

		if(head<tail)
		{
			int temp = *head;
			*head = *tail;
			*tail = temp;
		}
	}
}

bool IsEven(int i)
{
	return (i & 1)==0;
}


/************************************************************************/
/* 输出链表的第k个节点                                                                     */
/************************************************************************/
LinkNode *FindKthToTail(LinkNode *pLinkNode,unsigned int k)
{
	if(pLinkNode==NULL || k<=0)
		return NULL;
	LinkNode *pAhead = pLinkNode;
	LinkNode *pAfter = pLinkNode;
	for(unsigned int i=0;i<k-1;i++)
	{
		if(pAhead->next!=NULL)
			pAhead = pAhead->next;
		else
		{
			std::cout << "list length is smaller than k" << std::endl;
			return NULL;
		}
	}

	while (pAhead->next!=NULL)
	{
		pAhead = pAhead->next;
		pAfter = pAfter->next;
	}

	return pAfter;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//print1ToMaxOfNDigits(10);
	
	int arr[16];
	srand((unsigned int)time(NULL));
	for (int i=0;i<16;i++)
	{
		arr[i] = rand()%100;
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	ReorderOddEven(arr,16,IsEven);
	for (int i=0;i<16;i++)
	{
		std::cout << arr[i] << " ";
	}


	LinkNode *pHead = new LinkNode;
	pHead->value = 0;
	pHead->next = NULL;
	for (int i=1;i<10000;i++)
	{
		LinkNode *node = new LinkNode;
		node->value = i;
		node->next = pHead->next;
		pHead->next = node;
	}
	std::cout <<std::endl<< FindKthToTail(pHead,4000)->value << std::endl;
	while (pHead->next!=NULL)
	{
		LinkNode *node = pHead->next;
		pHead->next = node->next;
		delete node;
	}
	
	return 0;
}

