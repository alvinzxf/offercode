/*
第一个只出现一次的字符
题目描述

在一个字符串(1<=字符串长度<=10000，全部由大写字母组成)中找到第一个只出现一次的字符,并返回它的位置

解题思路：
利用哈希表，设定字符为哈希表中的键值(key)，字符出现次数为键值为值(value);
第一次扫描将字符出现的次数更新到哈希表中，
第二次扫描将哈希表在宏第一次出现值为1的字符找出，返回字符所在位置
每次扫描字符串的时间复杂度为O(n),扫描两次2*O(n),总的时间复杂度为O(n)
这里设置的哈希表的大小为256，因为字符是一个长度为8的数据类型，2的8次方为256，字符的各种组合总共有256种可能

*/
class Solution{
public:
	int FirstNotRepeatingChar(string str)
	{
		int length = str.length();
		if(length ==0)return -1;
		const int tableSize = 256;
		int hashTable[tableSize]={0};
		for(int i=0;i<length;++i)
			{
				hashTable[str[i]]++;
			}
		int index = 0;
		while(str[index]!='\0')
		{
			if(hashTable[str[index]]==1)
				return index;
			index++;
		}
		return -1;		
	}
};