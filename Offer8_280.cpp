// OfferCode.cpp : Defines the entry point for the console application.
/////////////////////////////////////////////////////////////////////////////
//************Author：alvinzxf*****************practise*****************/////
/***************************************************************************
按之字形顺序打印二叉树
题目描述
请实现一个函数按照之字形打印二叉树，
即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，
第三行按照从左到右的顺序打印，其他行以此类推。

解题思路：
首先设置两个栈stack1,stack2，其中一个栈stack1进头结点，另一个栈stack2用来存放头结点的左右孩子结点，
因为题目要求是从左到右与从右到左顺序交替，因此stack2存放头结点的孩子结点时从左往右存，stack1存放stack2中的结点的孩子时由右往左存
并将stack1与stack2中的数据序列存放到元素类型为vector的vector容器result中，将其返回

*/
#include "stdafx.h"
#include<vector>
#include<map>
#include<stack>
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
	vector<vector<int>>Print(TreeNode *pRoot)
	{
		vector<vector<int>>result;
		stack<TreeNode*>stack1, stack2;
		struct TreeNode* node;

		if (pRoot!=NULL)
			stack1.push(pRoot);
		while (!stack1.empty() || !stack2.empty())
		{
			//用于存储每一层的结点值
			vector<int>data;

			//从第一层开始将奇数层结点值存入data中，并将这一层的孩子结点放入stack2中，奇数层从左往右遍历
			
			if (!stack1.empty())
			{
				while (!stack1.empty())
				{
					node = stack1.top();
					stack1.pop();
					data.push_back(node->val);
					if (node->left != NULL)
						stack2.push(node->left);
					if (node->right != NULL)
						stack2.push(node->right);
				}

				//将基数层的结点值序列存入result中
				result.push_back(data);
			}
				
			else if (!stack2.empty())
			{
				//从第二层开始将偶数层的结点值存入data中，并将这一层的孩子结点放入stack1中，偶数层从右往左遍历
				while (!stack2.empty())
				{
					node = stack2.top();
					stack2.pop();
					data.push_back(node->val);
					if (node->right != NULL)
						stack1.push(node->right);
					if (node->left != NULL)
						stack1.push(node->left);
				}

				//将偶数层结点值序列存入result中
				result.push_back(data);
			}
			
		}
		return result;
	}
};

//若不按之字型
//是每一层都是从左往右打印，则可用队列实现

class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int>>result;
		if (pRoot == NULL)
			return result;
		queue<TreeNode*>node;
		node.push(pRoot);
		//nextLevel表示下一层的节点数，toBePrinted表示当前层中还没有打印的节点数
		int nextLevel = 0;
		int toBePrinted = 1;
		//用于存储每层的数据
		vector<int>data;
		while (!node.empty())
		{
			TreeNode *pNode = node.front();
			data.push_back(pNode->val);
			if (pNode->left != NULL)
			{
				node.push(pNode->left);
				nextLevel++;
			}

			if (pNode->right != NULL)
			{
				node.push(pNode->right);
				nextLevel++;
			}

			node.pop();
			--toBePrinted;
			if (toBePrinted == 0)
			{
				toBePrinted = nextLevel;
				nextLevel = 0;

				//每一层遍历结束时，将存放该层结点值的容器放入到result中并清除
				result.push_back(data);
				data.clear();
			}
		}
		return result;
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

