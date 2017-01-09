/*
从上往下打印二叉树
题目描述

从上往下打印出二叉树的每个节点，同层节点从左至右打印。
解题思路：
该打印过程可以看成按层遍历二叉树，我们用队列来实现结点的打印
若二叉树部为空，直接返回空
若二叉树不为空：
1，首先将二叉树的根节点进队列，将队头的结点出队，并结点值放入vector容器中,
并将结点的左孩子结点和右孩子结点进入队列中（左右孩子有可能为空）；
2，若队列不为空说明队列中还有结点，队列中左孩子结点位置在右孩子结点位置的前面,
3，依次将队头结点出队，若该出队的结点为空就跳出此次循环（因为有的结点的左孩子或右孩子为空，或根本没有叶子结点）
，继续下一个循环；不为空就继续将该结点的值放入vector容器，并将其左右孩子进队
4，若队列为空则说明该二叉树的结点已经没有叶子结点，二叉树遍历完毕

该问题用栈也可以实现
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
    vector<int> PrintFromTopToBottom(TreeNode *root) {
       queue<TreeNode*> q;
       q.push(root);
       vector<int> result;
        while(!q.empty()){
            root = q.front();
             q.pop();
            if(!root) continue;
            //continue跳过此次循环后面的代码继续开始下一个循环
            result.push_back(root -> val);
            q.push(root -> left);
            q.push(root -> right);
        }
        return result;
    }
};


