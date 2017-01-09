/*
二叉搜索树与双向链表
题目描述

输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
解题思路：
1,先用两个指针pCurrent,*pLastNodeInList来指向二叉搜索树的当前结点和及其左孩子结点，若当前结点不为空，则继续往左孩子搜索，递归调用该方法
2,使当前结点的左指针指向pLastNodeInList所指位置，若pLastNodeInList指向不为空，则使pLastNodeInList的右指针指向当前结点(pCurrent指向的位置)
	并将pLastNodeInList所指位置指向当前结点(pCurrent所指位置)；
3,往当前结点的右孩子结点搜索，递归调用该方法
*/

struct TreeNode
{
	TreeNode *left;
	TreeNode *right;
	int val;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution
{
public:
	void ConvertNode(TreeNode *pRoot,TreeNode **pLastNodeInList)
	{
		if(pRoot)return;
		TreeNode *pCurrent = pRoot;
		//若左子树不为空转换左子树
		if(pCurrent->left)
			ConvertNode(pCurrent->left,pLastNodeInList);

		pCurrent->left = pLastNodeInList;
		//如果当前结点左边的结点不为空，则使左边的结点指向(right指针)当前结点
		if(pLastNodeInList)
			(*pLastNodeInList)->right = pCurrent;
		//将pLastNodeInList指针指向当前结点所在位置，此时当前结点左边的所有结点已经转换完毕
		*pLastNodeInList = pCurrent;
		if(pCurrent->right)
			ConvertNode(pCurrent->right,pLastNodeInList);

	}

	TreeNode *Convert(TreeNode *pRoot)
	{
		TreeNode *pLastNodeInList = NULL;
		ConvertNode(pRoot,&pLastNodeInList);

		TreeNode *pHead = pLastNodeInList;
		//返回头结点
		while(pHead)
		{
			pHead = pHead->left;
		}
		return pHead;

	}

};
