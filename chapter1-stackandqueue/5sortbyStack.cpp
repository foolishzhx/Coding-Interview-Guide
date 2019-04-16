//
//用一个栈实现另一个栈的排序
//
#include <iostream>
#include <stack>
using namespace std;
stack<int> sortStackByStack(stack<int> st)
{
    stack<int> *help = new stack<int>;
    while(!st.empty())
    {
        int cur = st.top();
        st.pop();
        while(!help->empty() && help->top() < cur)
        {
            st.push(help->top());
            help->pop();
        }
        help->push(cur);
    }

    while (!help->empty())
    {
        st.push(help->top());
        help->pop();
    }
    help = NULL;
    delete help;
    return st;
}

int main()
{
    stack<int> st;
    stack<int> st1;
    int a[]={6,2,1,5,4,8,7,4,2,3,6,9,4,7,2,3,5};
    for (int i =0; i< sizeof(a)/ sizeof(a[0]);i++)
    {
        st1.push(a[i]);
        st.push(a[i]);
    }

    for (int i = 0; i < sizeof(a)/ sizeof(a[0]); i++)
    {
        cout << st.top() << endl;
        st.pop();
    }
    cout<<"after reverse:\n";
    st = sortStackByStack(st1);
    for (int i = 0; i < sizeof(a)/ sizeof(a[0]); i++)
    {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}
