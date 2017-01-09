/*
二叉树深度
题目描述
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
*/

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot==NULL)return 0;
        int nLeft = TreeDepth(pRoot->left);
        int nRight = TreeDepth(pRoot->right);
        return (nLeft>nRight)?(nLeft+1):(nRight+1);
    
    }
};


//平衡二叉树
/*题目描述
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
*/

#include "stdafx.h"
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	bool IsBalanced(TreeNode* pRoot,int *pDepth) {
		if (pRoot == NULL)
		{
			*pDepth = 0;
			return true;
		}
		int left, right;
		if (IsBalanced(pRoot->left, &left) && IsBalanced(pRoot->right, &right))
		{
			int diff = left - right;
			if (diff <= 1 && diff >= -1)
			{
				*pDepth = 1 + (left > right ? left : right);
				return true;
			}
		}
		return false;
	}
	bool IsBalanced_Solution(TreeNode* pRoot)
	{
		int depth = 0;
		return IsBalanced(pRoot, &depth);
	}
};