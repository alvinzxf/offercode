/*
包含min函数的栈

题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
*/

class Solution {
public:
    stack<int>dataStack,minStack;
    void push(int value) {
        dataStack.push(value);
        if(minStack.empty())
            minStack.push(value);
        else
           {
            int min  = minStack.top();
            value<min?minStack.push(value):minStack.push(min);
        }
            
         
    }
    void pop() {
        dataStack.pop();
        minStack.pop();
         
    }
    int top() {
        return dataStack.top();
         
    }
    int min() {
        return minStack.top();
    }
};