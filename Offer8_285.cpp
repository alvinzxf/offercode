// OfferCode.cpp : Defines the entry point for the console application.
/////////////////////////////////////////////////////////////////////////////
//************Author：alvinzxf*****************practise*****************/////
/***************************************************************************
二叉搜索树的第k个结点
题目描述
给定一颗二叉搜索树，请找出其中的第k大的结点。
例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，按结点数值大小顺序第三个结点的值为4


*/

#include "stdafx.h"
#include<vector>
#include<map>
#include<stack>
#include <string>
#include<algorithm>
#include<queue>
using namespace std;

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
	TreeNode *KthNode(TreeNode *pRoot, int k)
	{
		if (pRoot == NULL || k == 0)
			return NULL;
		return KthNodeCore(pRoot, k);

	}
	TreeNode* KthNodeCore(TreeNode *pRoot,int &k)
	{
		
		TreeNode *target = NULL;
		if (pRoot->left != NULL)
			target = KthNodeCore(pRoot->left, k);
		if (target == NULL)
		{
			if (k == 1)
				target = pRoot;
			k--;
		}
		if (target == NULL&&pRoot->right != NULL)
			target = KthNodeCore(pRoot->right, k);
		return target;
	
	}
	
};



int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

