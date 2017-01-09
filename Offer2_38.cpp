/*
二维数组中的查找

题目描述

在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

解题分析：因为二维数组的每行和每列都是按递增顺序排序了的，故在数组中的数字与目标数字比较时：
若目标数字比数组中的数字大，则目标数字的位置只能在数组当前数字所在列的左边与所在行的上边；
若目标数字比数组中的数字小，则目标数字的位置只能在数组当前数字所在列的右边与所在行的下边。
故比较的时候从可以从左下方开始比较，因为每次比较后：
若目标数字比数组当前的数字大，即可排除数组当前数字所在行下边的所有数字；
若目标数字比数组当前的数字小，即可排除数组当前数字所在列左边的所有数字
*/

class Solution {
public:
    bool Find(vector<vector<int> > array,int target) {
       
        int rowSize = array.size();		//数组的行数
        int colSize=array[0].size();	//数组的列数
        bool found = false;
        int i = rowSize - 1;			//记录数组的最后一行
        int j = 0;						//记录数组第一列
        for(;i>=0&&j<colSize;)
            {
            if(array[i][j] == target)	//从左下角开始比较
                {
                found = true;
                break;
            }
            if(array[i][j]< target)		//数组中的数比目标数字小，往右方找
                {
                j++;
                continue;
            }
            else						//数组中的输比目标数字大，往上方找
                {
                i--;
                 continue;
            }
        }
        return found;
    }
 };