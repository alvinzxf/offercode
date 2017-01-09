//数组中只出现一次的数字
/*
题目描述
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。

解题思路：
先从头到尾对数组中的每一个数字进行异或运算，得到的结果indexOf1,判断结果的二进制数中倒数第n位是为1，
再将数组分为两个子数组，分别为进行异或运算后倒数第n为为1的数字为一组，不为1的数字为一组
异或运算中，一个数异或本身的结果为0，最后的到两个子数组中的两个结果为两个所求的数字。


*/
class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		int size = data.size();
		if (size<=2)
		{
			return;
		}
		int resultExclusiveOR = 0;
		//对数组中所有的数字进行异或运算，得到结果resultExclusiveOR
		for (int i = 0; i < size; ++i)
		{
			resultExclusiveOR ^= data[i];
		}
		//算出二进制结果resultExclusiveOR中倒数第几位的数字为1
		int indexOf1 = FindFirstBitIs1(resultExclusiveOR);

		*num1 = 0;
		*num2 = 0;
		//对数组中的数字进行分组进行异或预算，resultExclusiveOR中倒数第indexOf1位
		for (int j = 0; j < size; ++j)
		{
			if (IsBit1(data[j], indexOf1))
				*num1 ^= data[j];
			else
				*num2 ^= data[j];
		}
	}

	int FindFirstBitIs1(int num)
	{
		int indexBit = 0;
		while ((num & 1) == 0 && (indexBit < 8 * sizeof(int)))
		{
			num = num >> 1;
			++indexBit;
		}
		return indexBit;
	}

	int IsBit1(int num, int indexBit)
	{
		num = num >> indexBit;
		return(num & 1);
	}
};



