/*
两个链表的第一个公共结点
题目描述
输入两个链表，找出它们的第一个公共结点。
*/


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
};

class Solution{
public:

	ListNode* FindFirstCommonNode(ListNode *pHead1,ListNode *pHead2)
	{
		int length1 = GetListLength(pHead1);
		int length2 = GetListLength(pHead2);
		int lengthDif =0;
		ListNode *pListHeadLong =NULL;
		ListNode *pListHeadShort =NULL;
		//得到两个链表的长度差，并用连个结点标记长短链表
		if(length1>length2)
		{
			pListHeadLong = pHead1;
			pListHeadShort =pHead2;
			lengthDif = length1-length2;
		}
		else
		{
			pListHeadLong = pHead2;
			pListHeadShort = pHead1;
			lengthDif = length2-length1;
		}
		//较长的链表先走几步
		for(int i=0;i<lengthDif;i++)
			pListHeadLong = pListHeadLong->next;
		//此时两个链表同时遍历
		while((pListHeadLong!=NULL)&&(pListHeadShort!=NULL)&&(pListHeadShort!=pListHeadLong))
		{
			pListHeadShort=pListHeadShort->next;
			pListHeadLong = pListHeadLong->next;
		}
		return pListHeadShort;
	}

	int GetListLength(ListNode *pHead)
	{
		int length =0;
		ListNode *pNode =pHead;
		while(pNode!=NULL)
		{
			pNode= pNode->next;
			length++;
		}
		return length;
	}
};


class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;
        while(p1!=p2){
            p1 = (p1==NULL ? pHead2 : p1->next);
            p2 = (p2==NULL ? pHead1 : p2->next);
        }
        return p1;
    }
};

class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
        map<ListNode*, int> m;
        ListNode *p = pHead1;
        while(p != NULL) {
            m[p] = 1;
            p = p->next;
        }
        p = pHead2;
        while(p != NULL) {
            if(m[p]) {
                return p;
            }
            p = p->next;
        }
        return NULL;
    }
};

class Solution{
public:
	ListNode *FindFirstCommonNode(ListNode *pHead1,ListNode *pHead2)
	{
		map<ListNode*,int > M;
		ListNode *pNode = pHead1;
		while(pNode!=NULL)
		{
			M[pNode] =1;
			pNode = pNode->next;
		}
		pNode = pHead2;
		while(pNode!=NULL)
		{
			if(M[pNode])
			{
				return pNode;
			}
			pNode = pNode->next;
		}
		return NULL;
	}
};