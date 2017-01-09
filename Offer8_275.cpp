// OfferCode.cpp : Defines the entry point for the console application.
/////////////////////////////////////////////////////////////////////////////
//************Author：alvinzxf*****************practise*****************/////
/***************************************************************************
二叉树的下一个结点
题目描述
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针.

解题思路：
1，若该结点有右子树，则其下一个结点就是右子树中最左边的子结点
2，若该结点没有右子树：
	a,若该结点为它父结点的左子树结点，则该结点下一个结点为其父结点
	b,若该结点为其父结点的右子树结点，则沿其父结点一直向上遍历，找到一个是它父结点的左子树的结点，
	   若这样的结点存在，则这个结点的父结点为要找的下一个结点，
	   若不存吓死，则说明题目要我们判断的那个结点为二叉树中最右子结点，其下一个结点为空

*/
#include "stdafx.h"
#include<vector>
#include<map>
#include<list>
#include<cmath>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode == NULL)
			return NULL;
		//右子树不为空，下一个结点在右子树中
		if (pNode->right != NULL)
		{
			pNode = pNode->right;
			//找到右子树中最左子结点
			while (pNode->left != NULL)
				pNode = pNode->left;
			return pNode;
		}
		//没有右子树，则向上找其父结点
		while (pNode->next != NULL)
		{
			TreeLinkNode *pParent = pNode->next;
			//如果其父结点有左子树，则该父结点为所求结点的下一个结点
			//否则，继续向父结点方向找父结点
			if (pParent->left == pNode)
				return pParent;
			pNode = pNode->next;
		}
		return NULL;
	}
};
//class Solution {
//public:
//	TreeLinkNode* GetNext(TreeLinkNode* pNode)
//	{
//		if (pNode == NULL)
//			return NULL;
//		TreeLinkNode *pResult = NULL;
//		if (pNode->right!=NULL)
//		{
//			TreeLinkNode *pTemp = pNode->right;
//			while (pTemp->left != NULL)
//				pTemp = pTemp->left;
//			pResult = pTemp;
//			return pResult;
//		}
//		else if (pNode->next != NULL)
//		{
//			TreeLinkNode *pCurrent = pNode;
//			TreeLinkNode *pParent = pNode->next;
//			while (pParent != NULL&&pCurrent == pCurrent->right)
//			{
//				pCurrent = pParent;
//				pParent = pParent->next;
//			}
//			pResult = pParent;
//			return pResult; 
//		}
//		
//		return NULL;
//		
//	}
//};


int _tmain(int argc, _TCHAR* argv[])
{

	
	return 0;
}

