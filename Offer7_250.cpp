// OfferCode.cpp : Defines the entry point for the console application.
/////////////////////////////////////////////////////////////////////////////
//************Author：alvinzxf*****************practise*****************/////
/***************************************************************************
把字符串转换成整数
题目描述
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
输入描述:
输入一个字符串,包括数字字母符号,可以为空


输出描述:
如果是合法的数值表达则返回该数字，否则返回0

输入例子:
+2147483647
1a33

输出例子:
2147483647
0

解题思路：
	首先判断字符串长度是否符合要求，字符串首字符是否为正负号；
	其次，对每个字符判断是否符合条件，若符合则：result = result*10+str[i];
*/
#include "stdafx.h"
#include<vector>
#include<list>
#include<cmath>
#include<iostream>
#include<string>
using namespace std;
class Solution{
public:
	
	int StrToInt(string str)
	{
		int result = 0;
		if (str.size() <= 0)return 0;
		int symbol = 1;
		if (str[0] == '-')
		{
			symbol = -1;
			str[0] = '0';
		}
		else if (str[0] == '+')
		{
			symbol = 1;
			str[0] = '0';
		}
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] < '0'|| str[i] >'9')
			{
				result = 0;
				break;
			}
			result = result * 10 + str[i] - '0';
		}
		
		return symbol*result;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution st;
	string str0 = "+2147483647";
	string str = "1a33";

	int result = st.StrToInt(str);
	int result1 = st.StrToInt(str0);

	cout << result1 << endl;
	cout << result << endl;
	
	return 0;
}

