/*
数组中的逆序对
题目描述

在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007 
输入描述:
题目保证输入的数组中没有的相同的数字
数据范围：
	对于%50的数据,size<=10^4
	对于%75的数据,size<=10^5
	对于%100的数据,size<=2*10^5


输入例子:
1,2,3,4,5,6,7,0

输出例子:
7

解题思路：
基于归并排序。
我们可将数据拆分成两个子数组，用两个指针分别指向每个子数组的末尾，每次比较两个指针指向的数字。若第一个子数组中的数字大于第二个子数组的数字，则构成逆序对；
每次比较时，我们都把较大的数字从后往前复制到一个辅助数组中，确保辅助数组中的数字是递增排序的。
再把较大的数字复制到辅助数组之后，把对应相应的指针往前移动一位，接下来进行下一轮比较。
对每次返回的count mod(1000000007)求余
*/



class Solution {
public:
    long long InversePairsCore(vector<int> &data,vector<int>&copy,int start,int end)
    {
        if(start==end)
        {
            copy[start]=data[start];
            return 0;
        }
        int length = (end-start)/2;
         //left为左边子数组中逆序对的个数，right为右边子数组中逆序对的个数
        long long left = InversePairsCore(copy,data,start,start+length);
        long long right = InversePairsCore(copy,data,start+length+1,end);
           
        int i = start + length;
        int j = end;
        int indexCopy = end;
         //此处的count为两个相邻数组间逆序对的个数
        long long  count=0;
        while(i>=start&&j>=start+length+1)
        {
        	//将两字子数组中相比较的较大的数字放入到copy数字中，
            if(data[i]>data[j])
            {
                copy[indexCopy--]=data[i--];
                //i,j都为从后往前移动，若左边的子数组的数字大于右边子数组的数字
                count+=j-start-length;
            }
             
            else
            {
                copy[indexCopy--]=data[j--];
            }
        }
        //将第一个子数组中剩余的数字放入copy中
        for(;i>=start;--i)
            copy[indexCopy--] = data[i];

        //将第二个子数组中剩余的数字放入copy中
        for(;j>=start+length+1;--j)
            copy[indexCopy--] = data[j];

        return left+right+count;
        }
    int InversePairs(vector<int> data) {
        int length = data.size();
        if(length<=0)
            return 0;
        vector<int> copy;
        for(int i=0;i<length;i++)
            copy.push_back(data[i]);
        long long  count = InversePairsCore(data,copy,0,length-1);
        copy.clear();
        return count%1000000007;
    }
      
      
};




class Solution{
public:
	long long InversePairsCore(vector<int >&data,vector<int> &copy,int start,int end)
	{
		if(start ==end)
		{
			copy[start]=data[start];
			return 0;
		}
		int length = (end-start)/2;
		int i = start+length;
		int j=end;
		int indexCopy = end;
		//leftCount,rightCount 分别为左边子数组和右边子数组逆序对的个数
		long long leftCount = InversePairsCore(copy,data,start,start+length);
		long long rightCount = InversePairsCore(copy,data,start+length+1,end);

		//count为两个子数组进行归并比较时逆序对的个数
		long long count = 0;
		while(i>=start && j>=start+length+1)
		{
			if(data[i]>data[j])
			{	
				copy[indexCopy--]=data[i--];
				count+=j-start-length;
			}
			else
			{
				copy[indexCopy--]=data[j--];
			}
		}
		//将两个子数组中剩余的数字放入到copy中
		for(;i>=start;--i)
			copy[indexCopy--]=data[i];
		for(;j>=start+length+1;--j)
			copy[indexCopy--] = data[j];
		return leftCount+rightCount+count;

	}


	int InversePairs(vector<int>data)
	{
		int length = data.size();

		if(length<=0)return 0;
		vector<int>copy;
		for(int i=0;i<length;i++)
			copy.push_back(data[i]);

		long long result = InversePairsCore(data,copy,0,length-1);
		//释放临时容器的元素
		copy.clear();
		return result%1000000007;
	}

};