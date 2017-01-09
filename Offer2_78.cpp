/*
二进制中1的个数

题目描述

输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
解题思路：
解法一：
    先将数字n与1作与运算，判断n的最低位是不是1，如果是，则将1的数目Count+1;
    将1左移一位，继续与n比较次地位的二进制数是不是1，反复地移位比较
	这种方法循环的次数为二进制数的位置

解法二：
	假设一个整数n不为0，那么这个整数至少有一位是1。
	若我们把这个整数减1，则整数最右边的1就会变为0，
	原来在1后面的所有的0都会变成1，其余所有位将不会改变。
	这个时候我们将n与n-1进行与运算，得到的结果相当于把n最后面的1变成0
	例如：
	一个二进制数1100，从右边数起第三位是右边的第一个1。
	将其减1后结果为：1011；发现减1的结果是把右边的第一个1开始的所有位取反。
	这是将1100与1011进行与运算，结果1100&1011=1000.
	1100右边第一个1那一位开始所有位都会变成0
	这种方法循环的次数为二进制数中1的个数在本例中循环的次数为2，若用解法一循环的次数则为4
*/
//解法一
class Solution{
	int NumberOf1(int n)
	{
		int NumbersOfOne =0;
		unsigned int flag =1;
		while(flag)
		{
			//依次将n从低位开始于flag进行与操作，
			//如果操作的结果为1，说明n的当前位数上的数为1，计数加1
			if(n&flag)
				NumbersOfOne++;
			//将flag左移一位
			flag = flag<<1;
		}
		return NumbersOfOne;
	}
};
//解法二
class Solution{
public:
	int NumberOf1(int n)
	{
		int NumbersOfOne = 0;
		while(n!=0)
		{
			++NumbersOfOne;
			n=n&(n-1);
		}
		return NumbersOfOne;
	}
};