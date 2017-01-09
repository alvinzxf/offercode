/*把二叉树打印成多行
题目描述
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。\
解题思路：
则可用队列实现
*/
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