// OfferCode.cpp : Defines the entry point for the console application.
/////////////////////////////////////////////////////////////////////////////
//************Author：alvinzxf*****************practise*****************/////
/***************************************************************************
滑动窗口的最大值
题目描述
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，
那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 
针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个：
{[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}，
{2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。

解题思路：
	1，简单的方法为将数组依次搜索，并做比较；
	2，另外一种思路是将有可能成为最大数值的下标存入到一个双端队列中，
		首先将钱size个数字做比较，将最大的数字的下标存入到index中，
		随后从第size个数字开始：数组下标为队列中的首个元素的数字存入到我们要找的容器中，
		若index不为空并且数组中出现比前一个(index.back() )可能的最大数字要大的数，则将index末端的数字出队，并将大的数字的下标进到队列index中
		若队列中首个数字比数组中当前下标与size的差还要小，则说明队列中的首个数字已经不在滑动窗口中，将其弹出

*/

#include "stdafx.h"
#include<vector>
#include<map>
#include<stack>
#include <string>
#include<algorithm>
#include<queue>
using namespace std;

//暴力搜索
class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{

		vector<int>result;
		if (size <= 0 || num.size() < size)return result;
		for (unsigned long i = 0; i <= num.size() - size; i++)
		{
			long max = 0;
			for (unsigned long j = i; (j < i + size) && (i + size) <= num.size(); j++)
			{
				if (j > num.size())
					return result;
				if (max < num[j])
					max = num[j];
			}
			result.push_back(max);
		}
		return result;

	}
};

class Solution{
public:
	vector<int>maxInWindows(const vector<int>&num, unsigned int size)
	{
		vector<int>maxInWindows;
		if (num.size() >= size&&size >= 1)
		{
			//index用于保存有可能是最大值数字的下标
			deque<int>index;
			for (unsigned int i = 0; i < size; i++)
			{
				while (!index.empty() && num[i] >= num[index.back()])
					index.pop_back();
				index.push_back(i);
			}
			for (unsigned int i = size; i < num.size(); ++i)
			{
				maxInWindows.push_back(num[index.front()]);

				while (!index.empty() && num[i] >= num[index.back()])
					index.pop_back();

					//index中数值下标小于当前数字下标与size之差，index的首个数字已经不在滑动窗口中
				if (!index.empty() && index.front() <= (int)(i - size))
					index.pop_front();

				index.push_back(i);
			}
			maxInWindows.push_back(num[index.front()]);
		}
		return maxInWindows;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

