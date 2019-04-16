//
//设计一个有getMIN功能的栈
//有问题
#include <iostream>
#include <stdlib.h>
#include <stack>
using namespace std;

class Getmin_stack
{
private:
    stack<int> stackData;
    stack<int> stackMin;
public:
    void Push(int data)
    {
        stackData.push(data);
        if (stackMin.empty())
        {
            stackMin.push(data);
        }
        else if(stackData.top() <= stackMin.top())
        {
                stackMin.push(data);
        }
    }

    void Pop()
    {
        if (stackData.top() == stackMin.top())//数据相等两个栈的数据都弹出
        {
            stackMin.pop();
            stackData.pop();
        }
        else
        {
            stackData.pop();
        }
    }

    int getMin()
    {
        return  stackMin.top();
    }

};

int main()
{
    int a[] = {5,4,3,2,1,2,3,4,5,5,4,4,3,3,2,1,2,1,1};
    Getmin_stack stack1;
    int i;
    int e;
    e = sizeof(a)/ sizeof(a[0]);
    for (i = 0; i < e; i++) {
        stack1.Push(a[i]);
    }
    while(1)
    {
        stack1.Pop();
        cout << "最小值是：" << stack1.getMin() << endl;
    }
    return 0;
}
