//
//仅用递归和栈 逆序一个栈
//这道题比较难想
#include <iostream>
#include <stack>
using namespace std;
int getLastElement(stack<int> &s) //递归调用时，对栈的操作，应使用栈的地址，否则开辟新的内存空间，使函数无限循环
{
    int result = s.top();
    s.pop();
    if (s.empty())
        return result;// 如果只有一个元素即为栈底的元素 返回
    else
    {
        int last = getLastElement(s); // 得到栈底元素
        s.push(result); // 并栈顶元素压栈
        return last;
    }
}

void reverseStack(stack<int> &s)
{
    if (s.empty())
        return;    // 递归结束的终止条件
    int i = getLastElement(s);    // 得到栈底的最后一个元素 剩下元素依旧
    reverseStack(s); // reverse 剩下
    s.push(i); // 将i push进去
}

int main()
{
    stack<int> st1;
    stack<int> st2;
    st1.push(1);
    st1.push(2);
    st1.push(3);
    st1.push(4);
    st1.push(5);
    st2 = st1;
    for (int i = 0; i < 5; i++)
    {
        cout << st1.top() << endl;
        st1.pop();
    }
    cout<<"after reverse:\n";
    reverseStack(st2);
    for (int i = 0; i < 5; i++)
    {
        cout << st2.top() << endl;
        st2.pop();
    }
    return 0;
}
