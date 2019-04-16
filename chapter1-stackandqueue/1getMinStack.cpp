//
//设计一个有getMIN功能的栈
//
#include <iostream>
#include <stdlib.h>
#include <stack>
using namespace std;

/*
 * 该特殊的栈在存储、删除数据时均可以返回最小值，不能用简单的变量去记录最小值
 * 因为pop出一部分数据之后，无法确定剩下的数据究竟最小的是什么
 */
class getMinStack
{
private:
    stack<int> stackData;
    stack<int> stackMin;
public:
    void Push(int data)
    {
        stackData.push(data);
        if (stackMin.empty())
            stackMin.push(data);
        else if (stackData.top() <= stackMin.top())
            stackMin.push(data);
    }

    void Pop()
    {
        if (stackData.top() == stackMin.top())//数据相等两个栈的数据都弹出
        {
            stackMin.pop();
            stackData.pop();
        }
        else
            stackData.pop();
    }

    int getMin()
    {
        return  stackMin.top();
    }

};

int main()
{
    int a[] = {5,4,3,2,1,2,3,4,5,5,4,4,3,3,2,1,2,1,1};
    getMinStack stack1;
    int len;
    len = sizeof(a)/ sizeof(a[0]);
    for (int i = 0; i < len; i++)
        stack1.Push(a[i]);
    for (int i = 0; i < len; i++)
    {
        stack1.Pop();
        cout << "最小值是：" << stack1.getMin() << endl;
    }
    return 0;
}
