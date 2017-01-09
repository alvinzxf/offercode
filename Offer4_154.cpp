/*
字符串的排列
题目描述

输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。 结果请按字母顺序输出。 
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
*/

class Solution
{
public:
	//遍历第begin位的所有可能性
	void Permutaion(vector<string>&array,string str,int begin)
	{
		if(begin == str.size()-1)
			array.push_back(str);
		for(int i= begin;i<=str.size()-1;i++)
		{
			//如果有重复字符，跳过此次循环
			if(i!=begin && str[i] ==str[begin])
				continue;
			//当i==begin时，遍历后面的所有字符
			//当i!=begin是，先交换，是第begin 位取到不同的可能字符，再遍历
			swap(str[i],str[begin]);
			//遍历后面的所有字符
			Permutaion(array,str,begin+1);
			//为防止重复，需要将begin出的元素复位
			swap(str[i],str[begin]);

		}
	}
	vector<string>Permutaion(string str)
	{
		vector<string> array;
		if(str.size()==0)
			return array;
		Permutaion(array,str,0);
		sort(array.begin(),array.end());
		return array;
	}

};