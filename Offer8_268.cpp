// OfferCode.cpp : Defines the entry point for the console application.
/////////////////////////////////////////////////////////////////////////////
//************Author：alvinzxf*****************practise*****************/////
/***************************************************************************
表示数值的字符串
题目描述
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。

解题思路：
	首先看第一个字符是不是正负号，如果是，在字符串上移动一个字符，继续扫描剩余的字符串0到9的数位，
	如果是一个小数，则将遇到小数点，另外，如果是科学计数法表示的数值，在整数或者小数的后面可能会遇到'e'或'E'。

*/
#include "stdafx.h"
#include<vector>
#include<list>
#include<cmath>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution{
public:
	void scanDigits(char **string)
	{
		while (**string != '\0'&&**string >= '0'&&**string <= '9')
			++(*string);
	}
	bool isExponential(char **string)
	{
		if (**string != 'e'&&**string != 'E')
			return false;
		++(*string);
		if (**string == '-' || **string == '+')
			++(*string);
		if (**string == '\0')
			return false;
		scanDigits(string);

		return (**string == '\0') ? true : false;
	}
	bool isNumeric(char *string)
	{
		if (string == NULL)
			return false;
		if (*string == '+' || *string == '-')
			++string;
		if (*string == '\0')
			return false; 
		bool numeric = true;
		scanDigits(&string);

		if (*string != '\0')
		{
			//浮点数情况
			if (*string == '.')
			{
				++string;
				scanDigits(&string);
				if (*string == 'e' || *string == 'E')
					numeric = isExponential(&string);
			}
			//整数情况
			else if (*string == 'e' || *string == 'E')
				numeric = isExponential(&string);
			else
				numeric = false;
		}
		return numeric && (*string == '\0');
	}
};



int _tmain(int argc, _TCHAR* argv[])
{
	
	return 0;
}

