/*
旋转数组的最小数字

题目描述:
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

解题思路：
解法一：
	将数组遍历一遍，找出最小的数，时间复杂度为O(n)，显然不是最优的解法，没有利用旋转数组的特征
*/
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int length = rotateArray.size();
        if(length<=0)return 0;
        int min = rotateArray[0];
        for(int i = 0; i<length;i++ )
            {
            if(rotateArray[i] < min)
                {
                min = rotateArray[i];
            }
        }
        return min;
        
    }
};
/*
解法二：
	由于旋转后的数组实际上可以划分为两个升序的子数组，前面子数组中数字的都大于后面子数组中的数；
	另外观察可发现，最小的数为两个子数组的交界点，利用二分查找可以找到最小的数字，时间复杂度为O(logn);

（1）我们用两个指针p1,p2分别指向数组的第一个元素和最后一个元素。按照题目的旋转的规则，第一个元素应该是大于最后一个元素的（只要数组中的数字不重复）。
但是如果不是旋转，第一个元素肯定小于最后一个元素。
（2）找到数组的中间元素。
	a)若中间元素大于第一个元素，则中间元素位于前面的递增子数组，此时最小元素位于中间元素的后面。我们可以让p1指向中间元素。
移动之后，第一个指针仍然位于前面的递增数组中。
	b)若中间元素小于第一个元素，则中间元素位于后面的递增子数组，此时最小元素位于中间元素的前面。我们可以让p2指向中间元素。
移动之后，第二个指针仍然位于后面的递增数组中。

（3）按照上述思路，p1总是指向前面递增数组的元素，p2总是指向后面递增的数组元素。
最终p1将指向前面数组的最后一个元素，p2指向后面数组中的第一个元素,即p1和p2相邻，p2所指的数字为最小的数字
*/

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int length = rotateArray.size();
        if(length<=0)return 0;
        //First指向前面子数组的第一个数，End指向后面子数组的最后一个数
        int First = 0;
        int End = length-1;
        int Mid = First;
        while(rotateArray[First] >=rotateArray[End])
            {
            if(End - First ==1)
                {
                Mid = End;
                break;
            }
            Mid = (First+End)/2;
            if(rotateArray[Mid] >= rotateArray[End])
                {
                First = Mid;
            }
            else 
                {
                End = Mid;
            }
        }
        
        return rotateArray[Mid];
        
    }
};

/*上述思路是在没有重复数字的情况下，继续考虑有重复数字的情况。

如：数组{1,0,1,1,1}和数组{1,1,1,0,1}都可以看做数组{0,1,1,1,1}的旋转数组
这里的First 和End都指向1，无法确定1是在前面的子数组还是后面的子数组中
这个时候我们则需要顺序查找
*/

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int length = rotateArray.size();
        if(length<=0)return 0;
        //First指向前面子数组的第一个数，End指向后面子数组的最后一个数
        int First = 0;
        int End = length-1;
        int Mid = First;
        while(rotateArray[First] >=rotateArray[End])
            {
            if(End - First ==1)
                {
                Mid = End;
                break;
            }
            Mid = (First+End)/2;
            //如果First,End,Mid指向数组中的数字都相同，则用顺序查找，就是解法一的方法
            if (rotateArray[First] == rotateArray[End] && rotateArray[Mid] == rotateArray[First])
            {
            	return MinInOrder(rotateArray,First,End);
            }
            if(rotateArray[Mid] >= rotateArray[End])
                {
                First = Mid;
            }
            else 
                {
                End = Mid;
            }
        }
        return rotateArray[Mid];
    }
    int MinInOrder(vector<int> rotateArray,int First,int End)
    {
    	int length = rotateArray.size();
        if(length<=0)return 0;
        int min = rotateArray[0];
        for(int i = 0; i<length;i++ )
            {
            if(rotateArray[i] < min)
                {
                min = rotateArray[i];
            }
        }
        return min;
    }
};
