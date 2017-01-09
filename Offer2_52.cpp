/*
从尾到头打印链表

题目描述

输入一个链表，从尾到头打印链表每个节点的值。 
输入描述:
输入为链表的表头


输出描述:
输出为需要打印的“新链表”的表头
*/

解题思路：把链表所有的结点值放入一个vector容器中
		先把头结点的值放入容器，再把头结点之后的结点值一个一个放入容器

struct ListNode{
	int val;
	struct Listnode *next;
	Listnode(int x):val(x),next(null){}
};
class Solution{
public:
    vector<int> printListFromTailToHead(struct ListNode* head) {
        std::vector<int> value;
        while (head)
        {
            value.insert(value.begin(),head->val);
            head=head->next;
             
        }
        return value;
    }
};