/*
重建二叉树

题目描述:
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

解题思路：
  1,先定义一个新结点head，将先序序列的第一个结点赋值给head，再从中序序列中找到头结点所在的位置，
  2,将中序序列中找到的位置记为Middle(从0开始计数),因为中序序列的长度和先序序列的长度是一样的;
故除了头结点之外：
先序序列的前Middle+1个结点和中序序列的前Middle个结点是头结点的左子树部分
先序序列的Middle+1后的结点和中序序列的Middle后的结点是头结点的右子树部分
  3,将左子树的先序序列和中序序列分别用两个容器left_pre和left_in来记录;
    将右子树的先序序列和中序序列分别用两个容器right_pre和right_in来记录
  4,分别对左子树部分和右子树部分进行重构操作，利用递归的方法求出最后的二叉树
*/

public class Solution {
    truct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
    	int length  =in.size();
    	if(length<=0)return NULL;
        TreeNode root=reConstructBinaryTree(pre,0,pre.length-1,in,0,in.length-1);
        return root;
    }
    //前序遍历{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}
    private TreeNode reConstructBinaryTree(vector<int> pre,int startPre,int endPre,vector<int> in,int startIn,int endIn) {
         int startPre = 0;
         int endPre = pre.size();
         int startIn = 0;
         int endIn = In.size();
        if(startPre>endPre||startIn>endIn ||endIn<=0)
            return null;
        TreeNode root=new TreeNode(pre[startPre]);
         
        for(int i=startIn;i<=endIn;i++)
            if(in[i]==pre[startPre]){
                root.left=reConstructBinaryTree(pre,startPre+1,startPre+i-startIn,in,startIn,i-1);
                root.right=reConstructBinaryTree(pre,i-startIn+startPre+1,endPre,in,i+1,endIn);
            }
                 
        return root;
    }
}

//解法2：
/**
 
     * Definition for binary tree
 
     * struct TreeNode {
 
     *     int val;
 
     *     TreeNode *left;
 
     *     TreeNode *right;
 
     *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 
     * };
 
     */

    class Solution {
 
    public:
 
        struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
        	int length = in.size();
        	if(length<=0)return NULL;
        	//Middle记录中序遍历序列中与先序遍历的头结点相同的位置
        	int Middle = 0;
        	//定义四个vector容器分别存储左右子树的先序遍历序列和中序遍历序列
        	std::vector<int> left_pre,left_in,right_pre,right_in;
        	//找到中序遍历序列中的头结点位置
        	for(int i = 0;i<length;i++)
        		if(in[i]==pre[0])
        		{
        			Middle = i;
        			break;
        		}
        		TreeNode *head = new TreeNode(pre[0]);
        	//将头结点左子树的先序序列和中序序列记录下来
        	for(int i = 0; i<Middle;i++)
        	{
        		left_pre.push_back(pre[i+1]);
        		left_in.push_back(in[i]);
        	}
        	//将头结点右子树的先序序列和中序序列记录下来
        	for(int i = Middle+1;i<length;i++)
        	{
        		right_pre.push_back(pre[i]);
        		right_in.push_back(in[i]);
        	}
        	head->left = reConstructBinaryTree(left_pre,left_in);
        	head->right = reConstructBinaryTree(right_pre,right_in);
        	return head;
    };





