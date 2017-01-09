// OfferCode.cpp : Defines the entry point for the console application.
/////////////////////////////////////////////////////////////////////////////
//************Author£ºalvinzxf*****************practise*****************/////
/***************************************************************************
ÕýÔò±í´ïÊ½Æ¥Åä
ÌâÄ¿ÃèÊö
ÇëÊµÏÖÒ»¸öº¯ÊýÓÃÀ´Æ¥Åä°üÀ¨'.'ºÍ'*'µÄÕýÔò±í´ïÊ½¡£
Ä£Ê½ÖÐµÄ×Ö·û'.'±íÊ¾ÈÎÒâÒ»¸ö×Ö·û£¬¶ø'*'±íÊ¾ËüÇ°ÃæµÄ×Ö·û¿ÉÒÔ³öÏÖÈÎÒâ´Î£¨°üº¬0´Î£©¡£
ÔÚ±¾ÌâÖÐ£¬Æ¥ÅäÊÇÖ¸×Ö·û´®µÄËùÓÐ×Ö·ûÆ¥ÅäÕû¸öÄ£Ê½¡£
ÀýÈç£¬×Ö·û´®"aaa"ÓëÄ£Ê½"a.a"ºÍ"ab*ac*a"Æ¥Åä£¬µ«ÊÇÓë"aa.a"ºÍ"ab*a"¾ù²»Æ¥Åä

½âÌâË¼Â·£º

*/
#include "stdafx.h"
#include<vector>
#include<list>
#include<cmath>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool matchCore(char *str, char *pattern)
	{
		if (*str == '\0'&&*pattern == '\0')
			return true;
		if (*str != '\0'&&*pattern == '\0')
			return false;
		if (*(pattern + 1) == '*')
		{
			if (*pattern == *str || (*pattern == '.'&&*str != '\0'))
			{
				return matchCore(str + 1, pattern + 2) || matchCore(str + 1, pattern) || matchCore(str, pattern + 2);
			}
			else
				return matchCore(str, pattern + 2);
		}
		if (*str == *pattern || (*pattern == '.'&&*str != '\0'))
			return matchCore(str + 1, pattern + 1);
		return false;
	}

	bool match(char *str, char *pattern)
	{
		if (str == NULL || pattern == NULL)
		{
			return false;
		}
		return matchCore(str, pattern);
	}

	
};


int _tmain(int argc, _TCHAR* argv[])
{
	Solution st;
	char *str = 'aaa';
	char *pattern = 'ab*a';
	bool result = st.match(str, pattern);
	int temp = 0;
	if (result == true)temp = 1;
	cout << temp << endl;
	
	return 0;
}

