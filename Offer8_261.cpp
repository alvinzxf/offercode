// OfferCode.cpp : Defines the entry point for the console application.
/////////////////////////////////////////////////////////////////////////////
//************Author：alvinzxf*****************practise*****************/////
/***************************************************************************
构建乘积数组
题目描述
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
不能使用除法。

解题思路：
详见https://www.nowcoder.com/questionTerminal/94a4d381a68b47b7a8bed86f2975db46

有题目意思可知: 若0<i<n-1,要使得B[i]= A[0]*A[1]*...*A[i-1]*...*A[n-1]  
首先可使B[i] = A[0]*A[1]*...*A[i-1]
	再使B[i] = B[i]*A[i+1]*...*A[n-1]

举例说明：设有数组大小为5。
对于第一个for循环
第一步：b[0] = 1;
第二步：b[1] = b[0] * a[0] = a[0]
第三步：b[2] = b[1] * a[1] = a[0] * a[1];
第四步：b[3] = b[2] * a[2] = a[0] * a[1] * a[2];
第五步：b[4] = b[3] * a[3] = a[0] * a[1] * a[2] * a[3];
然后对于第二个for循环
第一步
temp *= a[4] = a[4];
b[3] = b[3] * temp = a[0] * a[1] * a[2] * a[4];
第二步
temp *= a[3] = a[4] * a[3];
b[2] = b[2] * temp = a[0] * a[1] * a[4] * a[3];
第三步
temp *= a[2] = a[4] * a[3] * a[2];
b[1] = b[1] * temp = a[0] * a[4] * a[3] * a[2];
第四步
temp *= a[1] = a[4] * a[3] * a[2] * a[1];
b[0] = b[0] * temp = a[4] * a[3] * a[2] * a[1];
由此可以看出从b[4]到b[0]均已经得到正确计算。
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

