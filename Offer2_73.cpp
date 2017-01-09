/*斐波那契数列
题目描述
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
n<=39

*/
class Solution {
public:
    int Fibonacci(int n) {
        int i = 1;
        int first = 1;
        int second = 1;
        int sum = 0;
        if(n <= 2)
        {
            if(n==0)sum = 0;
            else
                sum =1;
        }
        if(n>2){
        	for(i=2;i<n;i++)
            {
            	sum = first+second;
                int temp = first;
            	first=second;
                second = first + temp;
        	}
            return sum;
        }
        return sum;
    }
};