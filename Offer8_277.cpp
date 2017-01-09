// OfferCode.cpp : Defines the entry point for the console application.
/////////////////////////////////////////////////////////////////////////////
//************Author：alvinzxf*****************practise*****************/////
/***************************************************************************
对称的二叉树
题目描述
题目描述
请实现一个函数，用来判断一颗二叉树是不是对称的。
注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。



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
	bool isSymmetrical(TreeNode*pRoot)
	{
		return isSymmetrical(pRoot, pRoot);
	}
	bool isSymmetrical(TreeNode*pRoot1, TreeNode *pRoot2)
	{
		if (pRoot1 == NULL && pRoot2 == NULL)
			return true;
		if (pRoot1 == NULL || pRoot2 == NULL)
			return false;
		if (pRoot1->val != pRoot2->val)
			return false;

		return isSymmetrical(pRoot1->left, pRoot2->right)
			&& isSymmetrical(pRoot1->right, pRoot2->left);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{

	
	return 0;
}

