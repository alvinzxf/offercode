// OfferCode.cpp : Defines the entry point for the console application.
/////////////////////////////////////////////////////////////////////////////
//************Author：alvinzxf*****************practise*****************/////
/***************************************************************************
翻转单词顺序列

题目描述
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，
	正确的句子应该是“I am a student.”。
	Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
	
解题思路：
	定义两个string 类型的对象，一个temp保存临时字符，一个result保存结果
	先用一个临时temp保存空格之前的字符，当遇到空格时，结果字符串result = 空格+temp +result;
	最后一个单词后面没有空格，因此还要讲最后一个temp加到result的前面

*/
#include "stdafx.h"
#include<vector>
#include<iostream>
#include<string>
using namespace std;

class Solution{
public:
	string ReverseSentence(string str)
	{
		string temp = "";
		string result = "";
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == ' ')
			{
				result = " " + temp + result;
				temp = "";
			}
			else
				temp += str[i];
		}
		if (temp.length())
		{
			result = temp + result;
		}
		return result;
	}

};
int _tmain(int argc, _TCHAR* argv[])
{
	string str = "abc XYZ def";
	string str1 = "abcdefg";
	Solution st =  Solution();
	str = st.ReverseSentence(str);
	cout << str << endl;
	return 0;
}

