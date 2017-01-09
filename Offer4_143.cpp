/*
二叉树中和为某一值的路径
题目描述

输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
解题思路：
用先序遍历的方式访问到某一个结点时，我们把该结点添加到路径上，并累加该结点的值，
如果该结点为叶结点并且路径中的结点值的和刚好等于输入的整数，则该路径刚好符合要求，将其打印出来
如果不是叶结点则继续访问其子结点，访问结束时，递归函数将自动回到父结点。
我们在函数退出之前要在路径上删除当前结点并减去当前结点的值，以确保返回父结点的路径刚好是根结点到父结点的路径。
保存路径的数据结构为一个栈， 路径要与递归调用状态一致，递归的本质就是一个压栈和出栈的过程
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
    vector<vector<int>>Result;
	vector<int>temp;
    void DFSFind(TreeNode* node ,int Number)
	{
		temp.push_back(node->val);
		//如果结点值与结点值相同，且结点的左右孩子为空，则将该结点作为路径保存到容器中
		if(Number - node->val==0&&!node->left&&!node->right)
			Result.push_back(temp);
		else{
			//若结点的左右孩子不为空，则对起左右子树进行深度搜索
			if(node->left)DFSFind(node->left,Number - node->val);
			if(node->right)DFSFind(node->right,Number - node->val);
		}
		//深度搜索后，将栈顶结点弹出，搜索回到上一个结点
		temp.pop_back();
	}
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root)DFSFind(root,expectNumber);
		return Result;
    }
    
};




struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){

	}
};

class Solution{
	vector<vector<int>>result;
	vector<int>temp;
	void DFSPath(TreeNode *root,int Number)
	{
		
		int CurrentNumber = 0;
		temp.push_back(root->val);
		CurrentNumber=CurrentNumber+root->val;
		//如果结点值与结点值相同，且结点的左右孩子为空，则将该结点作为路径保存到容器中
		if(CurrentNumber==Number&&root->left==NULL&&root->right==NULL)
		{
			result.push_back(temp);
		}
		else{
			//若结点的左右孩子不为空，则对起左右子树进行深度搜索
			if(root->left)DFSPath(root->left,Number-CurrentNumber);
			if(root->right)DFSPath(root->right,Number-CurrentNumber);
		}
		//深度搜索后，将栈顶结点弹出，搜索回到上一个结点
		temp.pop_back();
	}
	vector<vector<int>> FindPath(TreeNode *root,int expectNumber)
	{
		if (root!=NULL)
		{
			DFSPath(root,expectNumber);
		}
		return result;

	}
};



