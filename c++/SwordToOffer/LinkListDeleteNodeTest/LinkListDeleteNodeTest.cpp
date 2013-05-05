// LinkListDeleteNodeTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>

struct LinkNode
{
	int value;
	LinkNode *next;
};

/************************************************************************/
/* 常量时间删除节点i
	将i节点的后继节点j的内容复制到i 覆盖i节点的内容,删除j节点

/************************************************************************/
void DeleteNode(LinkNode **pListHead,LinkNode *pToBeDeleted)
{
	if(pListHead==NULL || pToBeDeleted==NULL)
		return;

	//如果被删除节点不是尾节点
	if(pToBeDeleted->next!=NULL)
	{
		LinkNode *pNext = pToBeDeleted->next;
		pToBeDeleted->value = pNext->value;
		pToBeDeleted->next = pNext->next;

		delete pNext;
		pNext = NULL;
	}
	else if(*pListHead==pToBeDeleted) //删除头节点（尾节点）只有一个节点
	{
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		*pListHead = NULL;

	}
	else 
	{
		LinkNode *pNext = *pListHead;
		while (pNext->next!=pToBeDeleted)
		{
			pNext = pNext->next;
		}
		pNext->next = NULL;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}

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


/************************************************************************/
/* 反转链表                                                                     */
/************************************************************************/
LinkNode *Reverse(LinkNode *pHead)
{
	if(pHead==NULL)
		return NULL;

	LinkNode *pNode = pHead->next;
	pHead->next=NULL;
	LinkNode *pPrev = pHead;
	while (pNode!=NULL)
	{	LinkNode *pTemp = pNode->next;
		pNode->next = pPrev;
		pPrev = pNode;
		pNode = pTemp;
	}
	return pPrev;
}

void print(LinkNode **pListHead)
{
	if(pListHead==NULL)
		return;
	LinkNode *node = *pListHead;
	while (node!=NULL)
	{
		std::cout << node->value<<std::endl;
		node = node->next;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	LinkNode **pHead;
	LinkNode *head = new LinkNode;
	LinkNode *tail = head;
	head->value = 0;
	head->next = NULL;
	pHead = &head;

	for (int i=1;i<10;i++)
	{
		LinkNode *node =  new LinkNode;
		node->value = i;
		node->next = NULL;
		tail->next = node;
		tail =  node;
	}
	
	print(pHead);
	LinkNode *node = *pHead;
	srand((unsigned int)time(NULL));
	int index = rand()%10;
	std::cout << "删除第"<<index<<"个节点" <<std::endl;
	for (int i=0;i<index;i++)
	{
		node = node->next;
	}
	DeleteNode(pHead,node);
	print(pHead);
	std::cout << "Reverse LinkList" <<std::endl;
	//(*pHead)->next=NULL;
	head = Reverse(*pHead);
	pHead = &head;
	print(pHead);

	return 0;
}

