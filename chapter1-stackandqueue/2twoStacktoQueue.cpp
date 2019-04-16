//
//用两个栈实现队列功能
//
#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class twoStacksQueue
{
public:
    void Push(T num)
    {
        stackpush.push(num);
    }

    void Pop()
    {
        if(stackpush.empty() && stackpop.empty())
            cerr << "The queue is empty" << endl;
        else if(stackpop.empty())
        {
            while(!stackpush.empty())
            {
                stackpop.push(stackpush.top());
                stackpush.pop();
            }
        }
        stackpop.pop();
    }

    T Front()
    {
        if (stackpush.empty() && stackpop.empty())
            cerr << "The queue is empty" << endl;
        else if (stackpop.empty())
        {
            while(!stackpush.empty())
            {
                stackpop.push(stackpush.top());
                stackpush.pop();
            }
        }
        return stackpop.top();
    }

    T Back()
    {
        T temp;
        if (stackpush.empty() && stackpop.empty())
            cerr << "The queue is empty" << endl;
        else if (stackpush.empty())
        {
            while(!stackpop.empty())
            {
                stackpush.push(stackpop.top());
                stackpop.pop();
            }
            temp = stackpush.top();
            return temp;
        }
        return stackpush.top();
    }

    unsigned long Size()
    {
        if (stackpush.empty() && stackpop.empty())
        {
            cerr << "The queue is empty" << endl;
            return 0;
        }
        return stackpush.size() + stackpop.size();
    }

    bool Empty()
    {
        return stackpop.empty() && stackpush.empty();
    }
private:
    stack<int> stackpush;
    stack<int> stackpop;
};

int main()
{
    int a[] = {5,4,3,2,1,2,3,4,5,5,4,4,3,3,2,1,2,1,1};
    twoStacksQueue<int> stack1;
    int len;
    len = sizeof(a)/ sizeof(a[0]);
    for (int i = 0; i < len; i++)
        stack1.Push(a[i]);
    while (!stack1.Empty())
    {
        cout << "头元素是：" << stack1.Front() << "*****尾元素是：" << stack1.Back() << endl;
        cout << "队列元素个数：" <<stack1.Size() << endl;
        stack1.Pop();
    }
    return 0;
}
