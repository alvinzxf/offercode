/*
数组中出现次数超过一半的数字

题目描述
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

解题思路：
简单的方法为将容器中的数字调用sort方法，使其排序，排序后的重复的数字都在其相邻位置，
我们要得出重复次数大于数组长度一半的数字，则只需要判断数组中当前位置的数字与当前位置+数组一半长度后 所在位置的数字是否相等

*/

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {

        int size = numbers.size() /2;
        sort(numbers.begin(),numbers.end());
        for(int i =0;i+size<numbers.size();i++)
            {
            if(numbers[i]==numbers[i+size])
                return numbers[i];
        }
        return 0; 
    }
};