/////////////////////////////////////////////////////////////////////////////
//************Author：alvinzxf*****************practise*****************/////
/***************************************************************************
孩子们的游戏(圆圈中最后剩下的数)

题目描述
每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,
今年亦是如此。HF作为牛客的资深元老,自然也准备了一些小游戏。
其中,有个游戏是这样的:首先,让小朋友们围成一个大圈。
然后,他随机指定一个数m,让编号为0的小朋友开始报数。每次喊到m-1的那个小朋友要出列唱首歌,
然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,
从他的下一个小朋友开始,继续0...m-1报数....
这样下去....直到剩下最后一个小朋友,可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。
请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)

*/
#include "stdafx.h"
#include<vector>
#include<list>

#include<iostream>
#include<string>
using namespace std;
class Solution{
public:
	int LastRemaining_Solution(int n, int m)
	{
		/*
		//解法一：
		if (n == 0)return -1;
		if (n == 1)return 0;
		else
		return (LastRemaining_Solution(n - 1, m) + m) % n;
		*/

		

		/*
		//解法二：
		if (n <= 0)return -1;
		int s = 0;
		for (int i = 2; i <= n; i++)
		{
			s = (s + m) % i;
		}
		return s;
		*/
		


	}
};
//解法三：
class List{
	int data;
	List *next;
	List(int num)
	{
		this->data = num;
	}
	friend class Solution;
};
class Solution{
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n == 0)return -1;
		if (n == 1)return 0;
		List *head = new List(0);
		List *tp = head;
		//将数字先放入链表中
		for (int i = 1; i < n; i++)
		{
			List *temp = new List(i);
			tp->next = temp;
			tp = temp;
		}
		tp->next = head;
		List *index = head;
		//当链表中不止一个结点时
		while (index->next != index)
		{
			List *Ind = NULL;
			for (int i = 0; i < m - 1; i++)
			{
				Ind = index;
				index = Ind->next;
			}
			//删除链表中为第m-1个结点
			index = index->next;
			Ind->next = index;
		}
		return index->data;

	}
};


class Solution{
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n < 0 || m < 1)
			return -1;
		if (n == 1)return 0;
		int i = 0;
		list<int>numbers;
		//将数字放入list容器numbers中
		for (i = 0; i < n; i++)
			numbers.push_back(i);

		list<int>::iterator current = numbers.begin();
		while (numbers.size()>1)
		{
			for (int i = 1; i < m; i++)
			{
				current++;
				//将指向末尾数字的标识重新指向首个数字
				if (current == numbers.end())
					current = numbers.begin();
			}
			//next为第m个数字后面一个数字
			list<int>::iterator next = ++current;
			if (next == numbers.end())
				next = numbers.begin();
			//将第m个数字删除
			--current;
			numbers.erase(current);
			current = next;
		}
		return *(current);

	}
};