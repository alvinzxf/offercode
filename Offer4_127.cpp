/*
顺时针打印矩阵

题目描述
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

解题思路：
我们将整个打印过程看成从外圈往内圈顺时针方向循环打印的过程，设循环圈数为start，行数为row,列数为col
通过简单分析可发现循环打印的条件为：row>start*2 && col>start*2
由于打印一圈有4个过程：
1，从左往右打印
2，从上往下打印，条件为终止行号大于起始行号
3，从右往左打印，条件为终止行号大于起始行号，同时满足终止列好大于起始列号
4，从下往上打印，条件为至少有3行2列，即要求终止行号比起始行号至少大2，终止列号必须大于起始列号

*/
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        if(matrix.empty())return matrix[0];
        int row = static_cast<int>(matrix.size());
        int col = static_cast<int>(matrix[0].size());
        int start =0 ;
        vector<int>result;
        result.clear();
        if(row<=0||col<=0)return result;
        while(row>start*2&&col>start*2)
            {
            int endX=col-start-1;
            int endY=row-start-1;
            //从左到右打印一行
            for(int i=start;i<=endX;i++)
                result.push_back(matrix[start][i]);
           
            //从上往下打印一列
            if(start<endY)
                for(int i=start+1;i<=endY;i++)
                	 result.push_back(matrix[i][endX]);
                //从右往左打印一行
            if(start<endX&&start<endY)
                for(int i=endX-1;i>=start;--i)
                	 result.push_back(matrix[endY][i]);
            if(start<endX&&start<endY-1)
                for(int i=endY-1;i>=start+1;--i)
                	 result.push_back(matrix[i][start]);
            start++;

                }
        return result;
    }
};




class Solution{
public:
	vector<int>printMatrix(vector<vector<int>> matrix)
	{
		if(matrix.empty())return matrix[0];
		int row=matrix.size();
		int col = matrix[0].size();
		int start=0;
		vector<int> result;
		result.clear();
		if(row<=0||col<=0)return result;
		while(row>start*2&&col>start*2)
		{
			int endX= col-start-1;
			int endY= row-start-1;
			//从左往右打印
			for(int i=start;i<=endX;i++)
				result.push_back(matrix[start][i]);
			//从上往下打印
			if(start<endY)
				for(int i=start+1;i<=endY;i++)
					result.push_back(matrix[i][endX]);
			//从右往左打印
			if(start<endY&&start<endX)
				for(int i=endX-1;i>=start;i--)
					result.push_back(matrix[endY][i]);
			//从下往上打印
			if(start<endY-1&&start<endX)
				for(int i=endY-1;i>=start+1;i--)
					result.push_back(matrix[i][start]);
			start++;
		}
		return result;
	}

};