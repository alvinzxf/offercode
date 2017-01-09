// OfferCode.cpp : Defines the entry point for the console application.
//
/*
和为S的两个数字
题目描述
输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
输出描述:
对应每个测试案例，输出两个数，小的先输出。

解题思路：
	首先判断x,y取值为什么时候，x*y最小；
	由条件：x+y =S，已知x>0,y>0,S>0；
	设G(x) = x*y =x(S-x),G(x) = -x^2 +S*x
	G(x)为二次函数，由图像可知，x与y越接近，G(x)越大，反之G(x)越小

	故我们对排序数组中两边夹逼查找，找到第一对数字，就是相距最远的，乘机为最小

*/
#include "stdafx.h"
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		vector<int>result;
		
		int i = 0;
		int j = array.size()-1;
		while (i < j)
		{
			if (array[i] + array[j] == sum)
			{
				result.push_back(array[i]);
				result.push_back(array[j]);
				break;

			}
			while (i < j && array[i] + array[j] > sum) --j;
			while (i < j && array[i] + array[j] < sum) ++i;
		}
		return result;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{

	return 0;
}

