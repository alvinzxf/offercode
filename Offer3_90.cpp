/*
数值的整数次方

题目描述
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

解题思路：
1，在计算之前先要检测base和n 的数值是否合法，如base为0或者n<0的情况
	base为0时由于double类型原因，不能直接用等于(==)来判断
2,计算base的exponent次方,当n为负数时先n转换为正数，再计算base的exponent次方，
3, 输出时再对n进行判断,若n为负数，则输出结果为正数情况下的结果的倒数
*/
//方法一：
class Solution {
public:
 double Power(double base, int n) {
 	double result = 1.0;
 	int exponent =0;
 	if((base-0.0)>-0.0000001 &&(base-0.0)<0.0001 &&(n<0))
 		return 0.0;
 	if(n>0)
 		exponent =n;
  	if(n<0)
  		exponent = -n;
  	for(int i=1;i<=exponent;i++)
  	{
  		result *=base;
  	}
  	return n > 0 ? result:1.0/result;   
	}
};

/*
以上方法是直接算的情况，计算次数为n的次数，时间复杂度为O(n);我们发现：
当n为偶数时 base^n = base^(n/2)  *  base^(n/2)
当n为偶数时 base^n = base^(n/2)  *  base^(n/2) *base
于是我们可以先求出Power(base,n/2)的情况，在根据n是偶数还是奇数再做一次运算;
这样我们可以将时间复杂度缩小到O(logn);
另外，我们用n右移一位代替除以2,用exponent与十六1作与运算来判断n是否为奇数，因为二进制的右移和与运算都比求余运算(%)要快
*/
//方法二：
class Solution{
public:
	double Power(double base, int n)
	{
		double result =1.0;
		if((base-0.0>-0.000001) &&(base-0.0<0.0000001) &&n<0)return 0.0;
		if(n==0)return 1;
		if(n ==1)return base;
		int exponent =n>0?n:-n;
		result = Power(base,exponent>>1); //用右移一位代替除以2
		result*=result;
		if(exponent &0x1 ==1)
			result*=base;
		return n>0?result:1.0/result;
	}
};

