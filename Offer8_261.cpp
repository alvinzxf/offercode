// OfferCode.cpp : Defines the entry point for the console application.
/////////////////////////////////////////////////////////////////////////////
//************Author��alvinzxf*****************practise*****************/////
/***************************************************************************
�����˻�����
��Ŀ����
����һ������A[0,1,...,n-1],�빹��һ������B[0,1,...,n-1],
����B�е�Ԫ��B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]��
����ʹ�ó�����

����˼·��
���https://www.nowcoder.com/questionTerminal/94a4d381a68b47b7a8bed86f2975db46

����Ŀ��˼��֪: ��0<i<n-1,Ҫʹ��B[i]= A[0]*A[1]*...*A[i-1]*...*A[n-1]  
���ȿ�ʹB[i] = A[0]*A[1]*...*A[i-1]
	��ʹB[i] = B[i]*A[i+1]*...*A[n-1]

����˵�������������СΪ5��
���ڵ�һ��forѭ��
��һ����b[0] = 1;
�ڶ�����b[1] = b[0] * a[0] = a[0]
��������b[2] = b[1] * a[1] = a[0] * a[1];
���Ĳ���b[3] = b[2] * a[2] = a[0] * a[1] * a[2];
���岽��b[4] = b[3] * a[3] = a[0] * a[1] * a[2] * a[3];
Ȼ����ڵڶ���forѭ��
��һ��
temp *= a[4] = a[4];
b[3] = b[3] * temp = a[0] * a[1] * a[2] * a[4];
�ڶ���
temp *= a[3] = a[4] * a[3];
b[2] = b[2] * temp = a[0] * a[1] * a[4] * a[3];
������
temp *= a[2] = a[4] * a[3] * a[2];
b[1] = b[1] * temp = a[0] * a[4] * a[3] * a[2];
���Ĳ�
temp *= a[1] = a[4] * a[3] * a[2] * a[1];
b[0] = b[0] * temp = a[4] * a[3] * a[2] * a[1];
�ɴ˿��Կ�����b[4]��b[0]���Ѿ��õ���ȷ���㡣
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
	vector<int>multiply(const vecotor<int>&A)
	{

		int size = A.size();
		vector<int>data(size);
		int ret = 1;
		for (int i = 0; i < size; i++)
		{
			data[i] = ret;
			ret *= A[i];
		}
		ret = 1;
		for (int i = size - 1; i >= 0; i--)
		{
			data[i] *= ret;
			ret *= A[i];
		}
		return data;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	
	
	return 0;
}

