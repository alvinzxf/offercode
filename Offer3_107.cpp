链表中倒数第k个结点
题目描述

输入一个链表，输出该链表中倒数第k个结点。

解题思路：
用两个指针p,pre指向链表的头结点，先将p向前移动k-1个位置，随后p,pre一起向后移动，当p到达链表尾部时，pre则为倒数第k个结点

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode *p =NULL;
        ListNode *pre = NULL;
        p =pListHead;
        pre =pListHead;
        if(pListHead==NULL||k<=0)return NULL;
        for(int i=1;i<k;++i)
            {
            	//这里一定要判断p->next是否为空
            if(p->next!=NULL)
                {
                p=p->next;
            }
            else
            {
                return	NULL;
            }
            	
        }   
        while(p->next!=NULL)
            {
            p=p->next;
            pre=pre->next;
        }
        return pre;
    }
};

另外也可以通过栈来实现，先将每个结点压入栈中，在依次将栈中的前k个结点出栈，第k个结点就是链表倒数第k个结点

#include<stack>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode *p =NULL;
        ListNode *pre = NULL;
        p =pListHead;
     	//count用来记住链表的结点数
        int count=0;
        Stack<ListNode> stac = new Stack<ListNode>();
        if(pListHead==NULL||k<=0)return NULL;
        while(p!=NULL)
            {
                stack.push(p);
            	p=p->next;
            	count++;
        }   
        //若结点数小于k则返回空
        if(count<k)return NULL;
        //依次将栈中的前k个结点出栈
        for(int i=k;i>0;k--)
            {
            pre=stack.pop();
        }
        return pre;
    
    }
};