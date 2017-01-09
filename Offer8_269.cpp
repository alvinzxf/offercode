// OfferCode.cpp : Defines the entry point for the console application.
/////////////////////////////////////////////////////////////////////////////
//************Author：alvinzxf*****************practise*****************/////
/***************************************************************************
字符流中第一个不重复的字符
题目描述
请实现一个函数用来找出字符流中第一个只出现一次的字符。
例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。

输出描述:
如果当前字符流没有存在出现一次的字符，返回#字符。
*/
#include "stdafx.h"
#include<vector>
#include<map>
#include<list>
#include<cmath>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//推荐解法一：
class Solution{
public:
	Solution():index(0){
		for (int i = 0; i < 256; i++)
			occurence[i] = -1;
		
	}
	
	void Insert(char ch)
	{
		if (occurence[ch] == -1)
			occurence[ch] = index;
		else if (occurence[ch] >= 0)
			occurence[ch] = -2;
		index++;
	}

	char FirstAppearingOnce()
	{
		char ch = '\0';
		int minIndex = numeric_limits<int>::max();
		for (int i = 0; i < 256; ++i)
		{
			if (occurence[i] >= 0 && occurence[i] < minIndex)
			{
				ch = char(i);
				minIndex = occurence[i];
			}
		}
		if (ch == '\0')
			return '#';
		return ch;
	}
private:
	int occurence[256];
	int index;
};


//推荐解法二：
class Solution{
public:
	//Insert one char from stringstream
	void Insert(char ch)
	{
		vec.push_back(ch);
		data[ch]++;
	}

	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		vector<int>::iterator it;
		for (it = vec.begin(); it != vec.end(); it++)
			if (data[*it] == 1)
				return *it;
		return '#'; 
	}
private:
	map<char, int>data;
	vector<int>vec;
};
int _tmain(int argc, _TCHAR* argv[])
{
	char *str = "googlefdf";

	
	return 0;
}

