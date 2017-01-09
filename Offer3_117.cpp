
/*
树的子结构
题目描述

输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

解题思路：判断树B是不是树A的子树
我们从树A的根节点开始搜索，如果树A与树B的根结点相同，则判断树A与树B的左孩子和右孩子是否相同，
否则分别从树A的左结点和右结点重新开始搜索比较
*/
struct TreeNode{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
}
class Solution{
public:
	bool HasSubtree(TreeNode* pRoot1,TreeNode* pRoot2){
		bool result = false;
		if(pRoot1!=NULL&&pRoot2!=NULL)
		{
			if(pRoot1->val == pRoot2->val)
				result = DoesTree1HaveTree2(pRoot1,pRoot2);
			if(!result)
				result =HasSubtree(pRoot1->left,pRoot2);
			if(!result)
				result =HasSubtree(pRoot1->right,pRoot2);
		}
		return result;
	}
	bool DoesTree1HaveTree2(TreeNode* pRoot1,TreeNode*pRoot2)
	{
		if(pRoot2==NULL)return true;
		if(pRoot1==NULL)return false;
		if(pRoot1->val != pRoot2->val)return false;
		return DoesTree1HaveTree2(pRoot1->left,pRoot2->left)&&DoesTree1HaveTree2(pRoot1->right,pRoot2->right);
	}
 };