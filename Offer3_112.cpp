/*
反转链表
题目描述

输入一个链表，反转链表后，输出链表的所有元素。
解题思路：
我们分别用四个指针pReversedHead,pNode,pPrev,pNext来指向反转链表的头结点，原链表的头结点、pNode的前一个结点、pNode的后一个结点
在原链表上反转会引起链表的断裂，并且是在pNode所指结点与下一个结点之间断裂，故用pReversedHead，pNode指向当前结点的前一个结点合当前结点，
pNext指向pNode的下一个结点，pNext即为断裂后的链表的首个结点
如下所示
反转前：
a-->b-->c-->d-->e
反转后：
a<--b<--c<--d<--e
刚开始pNode指向a，其他指针都指向null,若pNode不为空，这时把pNext指向pNode下一个结点b,
	1，若pNext为空，说明链表只有一个结点，直接将pReversedHead指向pNode指向的结点a ,pNode的next指向pPrev所指位置NULL，实现反转
		pPrev指向pNode所指位置a，pNode指向pNext所指位置NULL，实现pNode向下一个结点的移动，接下来pNode为NULL,跳出循环
	2，若pNext不为空，,pNode的next指向pPrev所指位置，实现反转（此时a已经与后面的b,c,d,e断开，因为a->next已经是NULL,不再是b）
		pPrev指向pNode所指位置a，pNode指向pNext所指位置b，实现pNode向下一个结点的移动，不断循环，直到pNext为NULL
*/

struct ListNode{
	int val;
	struct *ListNode next;
	ListNode(int x):val(x),next(NULL)
	{}
};

class Solution{
public:
	ListNode* ReverseList(ListNode* pHead)
	{
		ListNode* pReversedHead = NULL;
		ListNode* pNext = NULL;
		ListNode* pNode = pHead;
		ListNode* pPrev = NULL;
		while(pNode!=NULL)
		{
			pNext = pNode->next;
			if(pNext==NULL)
				pReversedHead = pNode;
			pNode->next = pPrev;
			pPrev = pNode;
			pNode = pNext;
		}
		return pReversedHead;
	}
};