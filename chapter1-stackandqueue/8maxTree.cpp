//
//构造数组的MaxTree
//不重复的数组，数组元素个数,时间复杂度Ｏ（ｎ），空间复杂度Ｏ（ｎ）
#include <iostream>
#include <vector>
#include <stack>
#include "BiTree.h"

using namespace std;

vector<int> getMaxTree(vector<int> arr)//将原始数组处理，生成父子关系结果，用下标记录
{
    size_t len = arr.size();
    vector<int> rst(len, -1);
    stack<int> st;
    for (int i =0; i < len ; i++)
    {
        while(!st.empty() && arr[i] > arr[st.top()])
        {
            if (arr[i] < arr[rst[st.top()]] || rst[st.top()] == -1)
                rst[st.top()] = i;
            st.pop();
        }
        if (!st.empty())
            rst[i] = st.top();
        st.push(i);
    }
    return rst;
}

BiTree* setMaxTree(vector<int> arr)//返回的是根节点，即head节点
{
    BiTree* head = nullptr;
    vector<BiTree> MaxTree(arr.size(), BiTree());
    vector<int> rst = getMaxTree(arr);
    if(rst.empty())
        cout << "数组为空，请重新输入！";
    for (int i = 0; i < arr.size(); i++)
    {
        if (MaxTree[i].getValue() == NULL)
            MaxTree[i].setValue(arr[i]);
        if (rst[i] != -1)
        {
            if (MaxTree[rst[i]].getLchild() == nullptr)
                MaxTree[rst[i]].setLchild(&MaxTree[i]);
            else if (MaxTree[rst[i]].getLchild()->getValue() > arr[i])
            {
                BiTree* tmp = MaxTree[rst[i]].getLchild();
                MaxTree[rst[i]].setLchild(&MaxTree[i]);
                MaxTree[rst[i]].setRchild(tmp);
            }
            else
                MaxTree[rst[i]].setRchild(&MaxTree[i]);
        }
        else
            head = &MaxTree[i];
    }
    return head;
}

int main()
{
    vector<int> arr = {1,3,9,2,5,8,7,6,4};
    stack<int> st ;
    BiTree *head = setMaxTree(arr);

    return 0;
}
