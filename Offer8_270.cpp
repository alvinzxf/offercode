// OfferCode.cpp : Defines the entry point for the console application.
/////////////////////////////////////////////////////////////////////////////
//************Author：alvinzxf*****************practise*****************/////
/***************************************************************************
链表中环的入口结点
题目描述
一个链表中包含环，请找出该链表的环的入口结点。
解题思路

解法一：由于题目已知，链表中肯定有环，我们可以用两个指针，previous和front分别指向头结点和头结点的下一个结点，
		两个指针同时向前走，每走一步，使两指针断开连接，重复此步骤，最后一个结点就是环入口结点

解法二：考虑普通情况（链表中有可能没有环），此时我们需要确定环中的任意一个结点，然后再确定环中节点数numbers，
		最后用两个指针指向链表中的头结点，其中一个先走numbers步，再使两指针同时向前走，最后相遇的即为环的入口结点

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


//解法一
class Solution{
public:
	ListNode *MeetingNode(ListNode *pHead)
	{
		if (pHead->next == NULL)
			return NULL;
		ListNode *previous = pHead;
		ListNode *front = pHead->next;
		while (front)
		{
			previous->next = NULL;
			previous = front;
			front = front->next;
		}
		return previous;
	}
};

//解法二：
class Solution{
public:
	ListNode *MeetingNode(ListNode *pHead)
	{
		if (pHead == NULL)
			return NULL;
		ListNode *pSlow = pHead->next;
		if (pSlow == NULL)
			return NULL;
		ListNode *pFast = pSlow->next;
		while (pSlow != NULL&&pFast != NULL)
		{
			if (pFast == pSlow)
				return pFast;
			pFast = pFast->next;
			pSlow = pSlow->next;
			if (pFast != NULL)
				pFast = pFast->next;
		}
		return NULL;
	}

	ListNode *EntryNodeOfLoop(ListNode *pHead)
	{
		
		//得到环中的任一结点
		ListNode *meetingNode = MeetingNode(pHead);
		if (meetingNode == NULL)
			return NULL;
		//得到环中结点个数
		int NodesOfLoop = 1;
		ListNode*pNode1 = meetingNode;
		while (pNode1->next != meetingNode)
		{
			pNode1 = pNode1->next;
			NodesOfLoop++;
		}
		//先移动一个指针NodesOfLoop步
		pNode1 = pHead;
		for (int i = 0; i < NodesOfLoop; i++)
		{
			pNode1 = pNode1->next;
		}
		//同时移动两个指针pNode1和pNode2
		ListNode *pNode2 = pHead;
		while (pNode1 != pNode2)
		{
			pNode1 = pNode1->next;
			pNode2 = pNode2->next;
		}
		return pNode1;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{

	
	return 0;
}

//自己另外一个解法：
/*
class Solution{
public:
	ListNode *EntryNodeOfLoop(ListNode *pHead)
	{
		ListNode *temp = pHead;
		ListNode *result = NULL;
		if (pHead == NULL)
			return result;
		map<ListNode*, int>data;
		
		for (int i = 0; i < sizeof(pHead); i++)
		{
			if (temp->val == 0)
				temp->val = 1;
			temp->val = 0;
			temp = temp->next;
		}
		temp = pHead;
		while (temp != NULL)
		{
			if (data[(temp->next)] == 1)
			{
				result = temp;
				return temp;
			}
				
			data[temp] = 1;
		}
		return result;
	}
};
*/