/*
假设有两个栈stack1,  stack2 ，用这两个栈来实现队列的push()  和  pop()  操作

分析：
进队：push()  操作，直接使用stack1.push()，将元素进栈即可
出队：pop()   操作，先判断stack2是否为空。
若不为空，则stack2直接出栈即可；
若为空，则将stack1中的元素全部出栈，并依次压入栈stack2中，再将stack2中的元素出栈，即可完成操作。

C++实现代码：
*/
class Solution
{
public:
    void push(int node) {
        //直接将数据从栈里压入，实现队列的Push操作
        stack1.push(node);
    }

    int pop() {
        int temp;
        if(stack2.empty())
            while(!stack1.empty())
            {
            temp = stack1.top();
            stack2.push(temp);
            stack1.pop();
        }
        temp = stack2.top();
        stack2.pop();
        return temp;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};