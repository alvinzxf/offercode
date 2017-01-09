// OfferCode.cpp : Defines the entry point for the console application.
/////////////////////////////////////////////////////////////////////////////
//************Author：alvinzxf*****************practise*****************/////
/***************************************************************************
数据流中的中位数

题目描述
如何得到一个数据流中的中位数？
如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

基本思路：
在剑指offer中有很多种思路，书中给出一种较好的思路为使用大根堆与小根堆；
1，为使数据排序，将数据流中的数据分两部分，左边的一部分在大根堆中，右边的一部分在小根堆中，
	大根堆的最大元素与小根堆的最小元素为数据流最中间两个相邻的元素
2，若数据流中的数据个数为基数个，在小根堆中取出堆顶元素，即为所求的中位数，否则取大小根堆的堆顶元素的平均数
3，为保证大小根堆数据元素个数相差不超过1，可在当前大小根堆的元素总数为奇数时将要插入的元素插入大根堆(插入后总数变为偶数)
    当前大小根堆元素总数位偶数时插入小根堆（插入后总数位奇数）
4，为保证小根堆的元素始终大于大根堆的元素，
    若在将元素插入到小根堆时，出现该元素比大根堆的堆顶元素要小的情况，则先将大根堆元素取出并插入到小根堆中，再将要插入的元素插入到大根堆
    同理，若在将元素插入到大根堆时，出现该元素比小根堆的堆顶元素要大的情况，则先将小根堆的堆顶取出并插入到大根堆中，再将该元素插入小根堆中
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


class Solution {
public:
	void Insert(int num)
	{
		//偶数时，放入小根堆(插入后元素总数为奇数)
		if (((min.size() + max.size()) & 1) == 0)
		{
			//若要插入的数字比大根堆的堆顶数字要小，先将数据插入大根堆，将大根堆排序后再将堆顶元素取出，取出后插入最小堆
			if (max.size() > 0 && num < max[0])
			{
				max.push_back(num);
				//调整最大堆
				push_heap(max.begin(), max.end(), less<int>());

				num = max[0];		//取出大根堆的最大值

				pop_heap(max.begin(), max.end(), less<int>()); 
				max.pop_back();
			}
			min.push_back(num);

			//调整小根堆
			push_heap(min.begin(), min.end(), greater<int>());
		}
		else						//奇数时放入大根堆
		{
			//若要插入的数字比最小堆的数字大，现将数据插入小根堆，将小根堆排序后再将堆顶元素取出，将其插入大根堆
			if (min.size()>0 && min[0] < num)
			{
				min.push_back(num);
				push_heap(min.begin(), min.end(), greater<int>());
				num = min[0];		//得到小根堆的最小值（堆顶）
				pop_heap(min.begin(), min.end(), greater<int>());
				min.pop_back();
			}
			max.push_back(num);
			push_heap(max.begin(), max.end(), less<int>());
		}
	}

	double GetMedian()
	{
		int size = min.size() + max.size();
		if (size == 0)
			return NULL;
		double median = 0;
		if ((size & 1) == 1)						    //奇数，取小根堆堆顶元素
			median = min[0];
		else	
			median = (double)(min[0] + max[0]) / 2;  	//偶数时，取平均

		return median;
	}

private:
	vector<int>min;
	vector<int>max;
	
};

//另外一种
class Solution 
{
public:
	void Insert(int num)
	{
		if (p.empty() || num <= p.top()) p.push(num);
		else q.push(num);
		if (p.size() == q.size() + 2) q.push(p.top()), p.pop();
		if (p.size() + 1 == q.size()) p.push(q.top()), q.pop();
	}
	double GetMedian()
	{
		return p.size() == q.size() ? (p.top() + q.top()) / 2.0 : p.top();
	}
private:
	priority_queue<int, vector<int>, less<int> > p;
	priority_queue<int, vector<int>, greater<int> > q;

};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

