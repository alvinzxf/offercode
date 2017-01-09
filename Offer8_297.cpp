// OfferCode.cpp : Defines the entry point for the console application.
/////////////////////////////////////////////////////////////////////////////
//************Author：alvinzxf*****************practise*****************/////
/***************************************************************************
机器人的运动范围
题目描述
地上有一个m行和n列的方格。
一个机器人从坐标0,0的格子开始移动，
每一次只能向左，右，上，下四个方向移动一格，
但是不能进入行坐标和列坐标的数位之和大于k的格子。 
例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
但是，它不能进入方格（35,38），因为3+5+3+8 = 19。
请问该机器人能够达到多少个格子？

解题思路：
	此题与矩阵中的路径类似，都是运用回溯法，从坐标（0，0）开始移动，当准备进入坐标（i,j）的格子时，
	通过检查坐标的数位和来判断是否能够进入，如果能够进入坐标为（i,j）的格子，
	再判断能否进入其周边四个相邻的格子（i-1,j）、（i,j-1）、（i+1,j）、（i,j+1）;

	与矩阵中的路径不同的是：当矩阵中的路径判断的格子(i,j)不符合条件时，该路径不能进入该格子，再后续是有可能进入该格子的（其有可能与路径中其他的点符合），
	而本题中的格子(i，j)如果不满足条件，该格子的访问标识永远为true，在后续依然是不可能进入该格子的（因为其依然不满足条件）

*/

#include "stdafx.h"
#include<vector>
#include<map>
#include<stack>
#include <string>
#include<algorithm>
#include<queue>
#include<xfunctional>
using namespace std;

class Solution{
public:
	int movingCount(int threshold, int rows, int cols)
	{
		bool *visited = new bool[rows*cols];
		//或者用memset(visited,0,rows*cols)代替
		for (int i = 0; i < rows*cols;i++)
		{
			visited[i] = false;
		}

		int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
		delete[]visited;
		return count;
	}

	int movingCountCore(int threshold, int rows, int cols, int row, int col, bool *visited)
	{
		int count = 0;
		if (row >= 0 && row < rows&&col >= 0 && col < cols
			&&getDigitSum(row) + getDigitSum(col) <= threshold
			&&!visited[row*cols + col])
		{
			visited[row*cols + col] = true;

			count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited)
				+ movingCountCore(threshold, rows, cols, row, col - 1, visited)
				+ movingCountCore(threshold, rows, cols, row + 1, col, visited)
				+ movingCountCore(threshold, rows, cols, row, col + 1, visited);
		}
		return count;
	}

	int getDigitSum(int number)
	{
		int sum = 0;
		while (number > 0)
		{
			sum += number % 10;
			number = number / 10;
		}
		return sum;
	}
};



int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

