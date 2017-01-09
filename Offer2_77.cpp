 /*
矩形覆盖

题目描述
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

解题思路：记把2*n的覆盖方法为f(n)；

先将一个小矩形竖着放：放下之后有  f(n-1)种方法

再将小矩形横着放：放下之后有 f(n-2)种方法

故n>2时，共有f(n-1)+f(n-2)种方法。
*/

class Solution {
public:
    int rectCover(int number) {
        int method=0;
        if(number<=2)
            {
            if(number<=0)
				method=0;
            else
				method=number;
        }
        else
            {
            method=rectCover(number-1)+rectCover(number-2);
        }
        return method;
    }
};