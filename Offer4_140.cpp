/*
二叉搜索树的后序遍历序列

题目描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
解题思路：
1，后续遍历序列的最后一个数字是根结点的值，数组中的前面的数字可以分两部分，一部分是比根结点值大(左子树部分)，一部分比根结点值小(右子树部分)
2，先用一个循环找到比根结点值小的数字，则数组中该数字及以前的数字都在左子树中，该数字和数组最后一个数字之前的数字都在根结点的右字数中；
3，我们分别对左子树和右子树进行类似的判断，若都满足以步骤1，则重复2，若循环完毕，数组中的数字都满足步骤1，返回true；若不满足步骤1的规则，则返回false;
*/
class Solution{
	bool judge(vector<int> &seq,int left,int right){
		if(left>=right)return true;
		int i = right;
		while(i>left &&seq[i-1]>seq[right]) --i;
		for(int j=i-1;j>=left;--j)if(seq[j]>a[right])return false;
		return judge(seq,left,i-1)&&judge(seq,i,right-1);
	}
public:
	bool VerifySquenceOfBST(vector<int>sequence)
	{
		if(!sequence.size())return false;
		return judge(sequence,0,sequence.size()-1);
	}
};

class Solution{
public:
	bool VerifySquenceOfBST(vector<int>sequence)
	{
		int size = sequence.size();
		if(size==0)return false;
		//对序列中的每个节点做判断
		while(--size)
		{
			int i=0;
			//此部分为序列中第size个结点的左子树部分
			while(sequence[i++]<sequence[size]);
			//此部分为序列中第size个结点的右子树部分
			while(sequence[i++]>sequence[size]);
			//若序列中前半部分不全小于根结点值，右半部分不全大于根结点值，
			//则i<size，该序列不是后续遍历序列
			if(i<size)return false;

		}
		return true;
	}
};

