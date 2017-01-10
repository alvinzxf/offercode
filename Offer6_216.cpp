// OfferCode.cpp : Defines the entry point for the console application.
//
/*
��ΪS����������
��Ŀ����
����һ����������������һ������S���������в������������ǵ����ǵĺ�������S������ж�����ֵĺ͵���S������������ĳ˻���С�ġ�
�������:
��Ӧÿ�����԰����������������С���������

����˼·��
	�����ж�x,yȡֵΪʲôʱ��x*y��С��
	��������x+y =S����֪x>0,y>0,S>0��
	��G(x) = x*y =x(S-x),G(x) = -x^2 +S*x
	G(x)Ϊ���κ�������ͼ���֪��x��yԽ�ӽ���G(x)Խ�󣬷�֮G(x)ԽС

	�����Ƕ��������������߼бƲ��ң��ҵ���һ�����֣����������Զ�ģ��˻�Ϊ��С

*/
#include "stdafx.h"
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		vector<int>result;
		
		int i = 0;
		int j = array.size()-1;
		while (i < j)
		{
			if (array[i] + array[j] == sum)
			{
				result.push_back(array[i]);
				result.push_back(array[j]);
				break;

			}
			while (i < j && array[i] + array[j] > sum) --j;
			while (i < j && array[i] + array[j] < sum) ++i;
		}
		return result;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{

	return 0;
}

