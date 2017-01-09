/*
替换空格

题目描述

请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy

解题思路：
在剑指offer上面有两种解法：
解法一：
	先将字符串扫描，若碰到空格，则将空格替换，后面字符串一次往后面移动；
	接着对替换后的字符串在进行扫描，重复前面的操作
这种方法每扫描到空格，都要将空格后面所有的字符串移动一次，若字符串的长度为n,则总的时间效率为O(n)

解法二：
	先对字符串扫面一次，记录下字符串的长度，同时在扫面的过程中记录下空格字符的个数；
	再为字符串增加长度，因为每用'%20'替代一次空格，将增加两个字符的长度，增加的长度为：2*空格数目
	用两个标识符indexOfstr和indexOfEnd分别指向原始字符串的末端和新增长度后的字符串末端
	将indexOfstr依次从后往前查找，就将扫描到的字符都往后移动到indexOfEnd所指的位置，
    只要找到了空格，就将indexOfEnd所指的位置分别以‘%20’补充，并且将indexOfEnd往前移动。
	这样所有的字符只需要移动一次，总的时间效率为O(n)
推荐使用第二种解法，以下为第二种方法的实现代码
*/

//length为系统规定字符串输出的最大长度，固定为一个常数
class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str ==NULL ||length<=0)return;
        //numberBlank记录空格的个数，strLength用来记录扫描到字符的长度
      	int numberBlank = 0;
        int strLength = 0;
        int i=0;
        while(str[i]!='\0')
            {
            if(str[i]==' ')
                {
               ++numberBlank;
            }
            i++;
            strLength++;
        }
        //newlength为扫描后增加字符长度后的总长度
        //indexOfstr指向字符的末端
        //indexOfEnd指向为字符新增空间后的最后一个位置
        int newlength = strLength + 2*numberBlank;
        int indexOfstr = strLength;
        int indexOfEnd = newlength;
        if(newlength>length)return;
        while(indexOfstr>=0&&indexOfEnd>indexOfstr)
            {
            	//由字符串末端的字符往前扫描
            	//若碰到空格，则以'%20'补齐，指向字符所占空间最后一个位置的标识符往前移动
            if(str[indexOfstr] == ' ')
                {
                str[indexOfEnd--] = '0';
                str[indexOfEnd--] = '2';
                str[indexOfEnd--] = '%';
            }
            else
                {
                	//若没有碰到空格，则将扫描到的字符移动到indexOfEnd所指的位置，并且将indexOfEnd往前移动
                str[indexOfEnd--]= str[indexOfstr];
            }
            indexOfstr--;
        }
	}
};
