// OfferCode.cpp : Defines the entry point for the console application.
/////////////////////////////////////////////////////////////////////////////
//************Author：alvinzxf*****************practise*****************/////
/***************************************************************************
序列化二叉树
题目描述
请实现两个函数，分别用来序列化和反序列化二叉树

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
	char* Serialize(TreeNode *root) {

		if (root == NULL)
			return "#";
		string str = to_string(root->val);
		str.push_back(',');
		char *Left = Serialize(root->left);
		char *Right = Serialize(root->right);
		char *ret = new char[strlen(Left) + strlen(Right) + str.size()];
		strcpy(ret, str.c_str());
		strcat(ret, Left);
		strcat(ret, Right);
		return ret;

	}
	TreeNode* Deserialize(char *str) {
		return Decode(str);
	}
	TreeNode *Decode(char *&str)
	{
		if (*str == '#')
		{
			str++;
			return NULL;
		}
		int num = 0;
		while (*str != ',')
			num = num * 10 + (*(str++) - '0');
		str++;
		TreeNode *root = new TreeNode(num);
		root->left = Decode(str);
		root->right = Decode(str);
		return root;
	}
};

class Solution {
public:
	char* Serialize(TreeNode *root) {
		data.clear();
		DFS_Serialize(root);
		int *result = new int[data.size()];
		for (unsigned int i = 0; i < data.size(); i++)
			result[i] = data[i];
		return (char*)result;
	}
	TreeNode* Deserialize(char *str) {
		int *st = (int*)str;
		return DFS_Deserialize(st);
	}

private:
	vector<int>data;
	void DFS_Serialize(TreeNode *pNode)
	{
		if (!pNode)
			data.push_back(0x2333);
		else
		{
			data.push_back(pNode->val);
			DFS_Serialize(pNode->left);
			DFS_Serialize(pNode->right);
		}
	}
	TreeNode *DFS_Deserialize(int *&st)
	{
		if (*st == 0x2333)
		{
			++st;
			return NULL;
		}
		TreeNode *Node = new TreeNode(*st);
		++st;
		Node->left = DFS_Deserialize(st);
		Node->right = DFS_Deserialize(st);
		return Node;

	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

