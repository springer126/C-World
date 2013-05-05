// Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
struct BinaryTreeNode
{
	int value;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};


bool DoesTree1HasTree2(BinaryTreeNode *pRoot1,BinaryTreeNode *pRoot2);

/************************************************************************/
/* 判断树pRoot2 是不是pRoot1的子树                                                         */
/************************************************************************/
bool HasSubTree(BinaryTreeNode *pRoot1,BinaryTreeNode *pRoot2)
{
	bool result  = false;
	if(pRoot1!=NULL && pRoot2!=NULL)
	{
		if(pRoot1->value==pRoot2->value)
			result = DoesTree1HasTree2(pRoot1,pRoot2);
		if (!result)
			result = DoesTree1HasTree2(pRoot1->left,pRoot2);
		if(!result)
			result = DoesTree1HasTree2(pRoot1->right,pRoot2);
	}
	return result;
}

bool DoesTree1HasTree2(BinaryTreeNode *pRoot1,BinaryTreeNode *pRoot2)
{
	if(pRoot2==NULL)
		return true;

	if(pRoot1==NULL)
		return false;

	if (pRoot1->value!=pRoot2->value)
	{
		return false;
	}

	return DoesTree1HasTree2(pRoot1->left,pRoot2->left) &&
		DoesTree1HasTree2(pRoot1->right,pRoot2->right);
}

//BinaryTreeNode *BuildTree(int *arr,int length)
//{
//	if(arr==NULL && length<=0)
//		return;
//	BinaryTreeNode *pRoot = new BinaryTreeNode;
//	pRoot->value = arr[0];
//	pRoot->left = pRoot->right = NULL;
//	
//	BinaryTreeNode  *pCur = pRoot;
//	for (int i=0;i<n;i++)
//	{
//		BinaryTreeNode *pNode = new BinaryTreeNode;
//		pNode->value = i+1;
//		pNode->left = pNode->right = NULL;
//		if(pCur->left==NULL)
//			pCur->left = pNode;
//		else
//		{
//			pCur->right = pNode,
//			pCur  = pNode; 
//		}
//	}
//};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

