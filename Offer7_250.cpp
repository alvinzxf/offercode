// OfferCode.cpp : Defines the entry point for the console application.
/////////////////////////////////////////////////////////////////////////////
//************Author��alvinzxf*****************practise*****************/////
/***************************************************************************
���ַ���ת��������
��Ŀ����
��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯���� ��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0
��������:
����һ���ַ���,����������ĸ����,����Ϊ��


�������:
����ǺϷ�����ֵ����򷵻ظ����֣����򷵻�0

��������:
+2147483647
1a33

�������:
2147483647
0

����˼·��
	�����ж��ַ��������Ƿ����Ҫ���ַ������ַ��Ƿ�Ϊ�����ţ�
	��Σ���ÿ���ַ��ж��Ƿ������������������result = result*10+str[i];
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

