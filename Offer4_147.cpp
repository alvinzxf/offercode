
/*复杂链表的复制
题目描述

输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
解题思路：
        1、复制每个节点，并将该结点的复制结点插入到该结点后面，
        如：链表为：A->B->C->D, 经过复制步骤后的链表为：A->A1->B->B1->C->C1->D->D1
        2、遍历链表，A1->random = A->random->next;
        3、将链表拆分成原链表和复制后的链表
*/

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead)return NULL;
        RandomListNode *pCurrent = pHead;
        // 复制每个节点，并将该结点的复制结点插入到该结点后面，
        while(pCurrent)
            {
            RandomListNode *pCloned = new RandomListNode(pCurrent->label);
            
            pCloned->next = pCurrent->next;
            pCurrent->next = pCloned;
            pCurrent = pCloned->next;
            
        }
        //根据每个结点的Random指针情况处理每个复制结点的Random指针
        //前一个步骤结束后，pCurrent指向结点的尾部，下一步应从头开始处理
        pCurrent = pHead;
        while(pCurrent)
            {
            RandomListNode *pCloned = pCurrent->next;
            if(pCurrent->random)
                {
                pCloned->random = pCurrent->random->next;
            }
            pCurrent=pCloned->next;
        }
        //将链表的原始结点与复制结点断开，并使原始结点构成一个链表，复制结点构成一个链表
        //进行下一步pCurrent应从头开始
        pCurrent = pHead;
        RandomListNode *pClonedHead = pHead->next;
        RandomListNode *pClonedCurrent ;
      
        while(pCurrent->next)
            {
            pClonedCurrent = pCurrent->next;
           
            pCurrent->next = pClonedCurrent->next;
            pCurrent = pClonedCurrent;
        }
        return pClonedHead;
         
    }
};