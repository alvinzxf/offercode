// OfferCode.cpp : Defines the entry point for the console application.
/////////////////////////////////////////////////////////////////////////////
//************Author��alvinzxf*****************practise*****************/////
/***************************************************************************
��ת����˳����

��Ŀ����
ţ���������һ����Ա��Fish��ÿ���糿���ǻ�����һ��Ӣ����־��дЩ�����ڱ����ϡ�
ͬ��Cat��Fishд�������ĸ���Ȥ����һ������Fish������������ȴ������������˼��
���磬��student. a am I������������ʶ������һ�ԭ���Ѿ��ӵ��ʵ�˳��ת�ˣ�
	��ȷ�ľ���Ӧ���ǡ�I am a student.����
	Cat��һһ�ķ�ת��Щ����˳��ɲ����У����ܰ�����ô��
	
����˼·��
	��������string ���͵Ķ���һ��temp������ʱ�ַ���һ��result������
	����һ����ʱtemp����ո�֮ǰ���ַ����������ո�ʱ������ַ���result = �ո�+temp +result;
	���һ�����ʺ���û�пո���˻�Ҫ�����һ��temp�ӵ�result��ǰ��

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

