调整数组顺序使奇数位于偶数前面

题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，
并保证奇数和奇数，偶数和偶数之间的相对位置不变。

解题思路：
1，我们可以利用冒泡排序，从头开始对数组开始扫描，若发现第一个偶数时，取出偶数，
则将后面的奇数往前移，并将这个偶数放到第二个偶数的前面；重复扫描
这样的时间复杂度为O(n*n)

2，我们利用迭代器和容器则可以快很多，
每发现一个偶数，我们将它放到一个偶数的容器中，并将原数组中的偶数删除掉，erase方法会自动将后面的元素往前移动，补充掉删掉的位置
我们重新将迭代器指向删掉偶数的容器，因为每调用一次erase迭代器指向的位置会失效
最后我们再将偶数容器的数放入到原来的数组中
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int size = array.size();
        if(size<=0)return;
        vector<int>arrayOdds;
        vector<int>arrayNotOdds;
        vector<int>::iterator index;
        index = array.begin();
        for(;index!=array.end();)
            {
            if(*index%2==0)
                {
                arrayOdds.push_back(*index);
                index = array.erase(index);
            }
                
            else
            	index++;
        }
        int OddsNumber = arrayOdds.size();
        if(OddsNumber>0)
            {
            for(int i=0;i<OddsNumber;i++)
                {
                array.push_back(arrayOdds[i]);
            }
        }        
    }
};
