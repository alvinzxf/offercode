// OfferCode.cpp : Defines the entry point for the console application.
/////////////////////////////////////////////////////////////////////////////
//************Author：alvinzxf*****************practise*****************/////
/***************************************************************************
左旋转字符串
题目描述
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，
就是用字符串模拟这个指令的运算结果。
对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，
即“XYZdefabc”。是不是很简单？OK，搞定它！

解题思路：
将每一个字符与之前的它前面第n个字符替换，再将原始前n个字符放到移动后字符的后面
*/
#include "stdafx.h"
#include<vector>
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	Solution(){}
	string LeftRotateString(string str, int n)
	{
		string temp;
		int length = str.length();
		if (length < n)return "";
		for (int i = 0; i < n; i++)
			temp.push_back(str[i]);
		for (int i = 0; i < length - n; i++)
		{
			str[i] = str[i + n];
		}
		
		for (int i = 0; i < n; i++)
		{
			str[length-n+i] = temp[i];
		}
		return str;
	}
	~Solution(){}
};

int _tmain(int argc, _TCHAR* argv[])
{
	string str = "abcXYZdef";
	string str1 = "abcdefg";
	Solution st =  Solution();
	str = st.LeftRotateString(str, 3);
	cout << str << endl;

	str1 = st.LeftRotateString(str1, 2);
	cout << str1 << endl;
	return 0;
}

