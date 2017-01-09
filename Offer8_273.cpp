// OfferCode.cpp : Defines the entry point for the console application.
/////////////////////////////////////////////////////////////////////////////
//************Author：alvinzxf*****************practise*****************/////
/***************************************************************************
删除链表中重复的结点
题目描述
在一个排序的链表中，存在重复的结点，
请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
解题思路：
	首先确定删除函数的参数，头结点有可能与后面的结点重复，故头结点有可能被删除，
	从头到尾遍历链表，若当前结点pNode与下一个结点pNext值相同，则它们是重复的结点，可以被删除，
	保存当前结点的前一个结点，并且使其与下一个值比其大的结点相连，确保pPreNode始终与下一个没有重复的结点连在一起

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
struct ListNode{
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};


class Solution{
public:
	ListNode *deleteDuplication(ListNode *pHead)
	{
		if (pHead == NULL )
			return NULL;
		ListNode *pPreNode = NULL;
		ListNode *pNode = pHead;
		while (pNode != NULL)
		{
			ListNode* pNext = pNode->next;
			bool needDelete = false;
			if (pNext != NULL&&pNext->val == pNode->val)
				needDelete = true;
			//若没有重复结点
			if (!needDelete)
			{
				pPreNode = pNode;
				pNode = pNode->next;
			}
			else              //有重复结点
			{
				int value = pNode->val;
				ListNode *pToBeDel = pNode;
				while (pToBeDel != NULL&&pToBeDel->val == value)
				{
					pNext = pToBeDel->next;

					delete pToBeDel;
					pToBeDel = NULL;

					pToBeDel = pNext;
				}
				if (pPreNode == NULL)
					pHead = pNext;
				else
					pPreNode->next = pNext;
				pNode = pNext;
			}
		}
		return pHead;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{

	
	return 0;
}

