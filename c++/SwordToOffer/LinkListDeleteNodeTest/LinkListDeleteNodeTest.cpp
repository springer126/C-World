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
/* ����ʱ��ɾ���ڵ�i
	��i�ڵ�ĺ�̽ڵ�j�����ݸ��Ƶ�i ����i�ڵ������,ɾ��j�ڵ�

/************************************************************************/
void DeleteNode(LinkNode **pListHead,LinkNode *pToBeDeleted)
{
	if(pListHead==NULL || pToBeDeleted==NULL)
		return;

	//�����ɾ���ڵ㲻��β�ڵ�
	if(pToBeDeleted->next!=NULL)
	{
		LinkNode *pNext = pToBeDeleted->next;
		pToBeDeleted->value = pNext->value;
		pToBeDeleted->next = pNext->next;

		delete pNext;
		pNext = NULL;
	}
	else if(*pListHead==pToBeDeleted) //ɾ��ͷ�ڵ㣨β�ڵ㣩ֻ��һ���ڵ�
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
/* �������ĵ�k���ڵ�                                                                     */
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
/* ��ת����                                                                     */
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
	std::cout << "ɾ����"<<index<<"���ڵ�" <<std::endl;
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

