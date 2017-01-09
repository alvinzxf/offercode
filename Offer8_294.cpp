// OfferCode.cpp : Defines the entry point for the console application.
/////////////////////////////////////////////////////////////////////////////
//************Author：alvinzxf*****************practise*****************/////
/***************************************************************************
矩阵中的路径
题目描述
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。
例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bccced"的路径，但是矩阵中不包含"abcb"路径，
因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。

思路：
本题可以利用回溯法的递归特性，路径可以看成一个栈，当矩阵中定位了路径前面n个字符的位置后，在与第n个字符对应的格子的周围
都没有找到第n+1个字符，这个时候只好回到第n-1个字符，重新定位第n个字符

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
	bool hasPath(char *matrix, int rows, int cols, char*str)
	{
		if (matrix == NULL || rows < 1 || cols < 1 || str == NULL)
			return false;
		bool *visited = new bool[rows*cols];
		memset(visited, 0, rows*cols);

		int pathLength = 0;
		for (int row = 0; row < rows; row++)
		{
			for (int col = 0; col < cols; col++)
				if (hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited))
					return true;
		}
		delete[] visited;

		return false;
	}

	bool hasPathCore(char *matrix, int rows, int cols, int row, int col,
		char *str, int &pathLength, bool *visited)
	{
		if (str[pathLength] == '\0')
			return true;
		bool hasPath = false;
		if (row >= 0 && row < rows&&col >= 0 && col < cols
			&&matrix[row*cols + col] == str[pathLength]
			&& !visited[row*cols + col])
		{
			++pathLength;
			visited[row*cols + col] = true;

			hasPath = hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited)
				|| hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited)
				|| hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited)
				|| hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited);
			if (!hasPath)
			{
				--pathLength;
				visited[row*cols + col] = false;
			}
		}
		return hasPath;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

