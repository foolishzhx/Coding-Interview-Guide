//2018.12.16
//分别用递归和非递归方式实现二叉树的前、中、后序遍历
//
#include <iostream>
#include <vector>
#include <stack>
#include "BiTree.h"
using namespace std;

void preorderRecur(BiTree *head)//前序遍历
{
    if (head == NULL)
        return;
    cout << head->value << "  ";
    preorderRecur(head->lchild);
    preorderRecur(head->rchild);
}

void preorderUnRecur(BiTree *head)
{
    stack<BiTree*> st;
    BiTree *ptr = head;
    while (ptr || !st.empty())
    {
        if (ptr)
        {
            cout << ptr->value << "  ";
            st.push(ptr);
            ptr = ptr->lchild;
        }
        else
        {
            ptr = st.top();
            ptr = ptr->rchild;
            st.pop();
        }
    }
}

void inorderRecur(BiTree *head)//中序遍历
{
    if (head == NULL)
        return;
    inorderRecur(head->lchild);
    cout << head->value << "  ";
    inorderRecur(head->rchild);
}

void inorderUnRecur(BiTree *head)
{
    stack<BiTree*> st;
    BiTree *ptr = head;
    while (ptr || !st.empty())
    {
        if (ptr)
        {
            st.push(ptr);
            ptr = ptr->lchild;
        }
        else
        {
            ptr = st.top();
            cout << ptr->value << "  ";
            ptr = ptr->rchild;
            st.pop();
        }
    }
}

void postorderRecur(BiTree *head)//后序遍历
{
    if (head == NULL)
        return;
    postorderRecur(head->lchild);
    postorderRecur(head->rchild);
    cout << head->value << "  ";
}

void postorderUnRecur(BiTree *head)
{
    stack<BiTree*> st;
    BiTree *ptr = head;
    BiTree *tmp = NULL;
    while (ptr || !st.empty())
    {
        if (ptr)
        {
            st.push(ptr);
            ptr = ptr->lchild;
        }
        else
        {
            ptr = st.top();
            if (ptr->rchild && ptr->rchild != tmp)//记录右子树是否遍历
                ptr = ptr->rchild;
            else
            {
                cout << ptr->value << "  ";
                tmp = ptr;
                ptr = NULL;
                st.pop();
            }
        }
    }
}

int main()
{
    BiTree *head = setTree();
    cout << "前序遍历（递归）：\n";
    preorderRecur(head);
    cout << "\n**************\n";
    cout << "前序遍历（非递归）：\n";
    preorderUnRecur(head);
    cout << "\n**************\n";
    cout << "中序遍历（递归）：\n";
    inorderRecur(head);
    cout << "\n**************\n";
    cout << "中序遍历（非递归）：\n";
    inorderUnRecur(head);
    cout << "\n**************\n";
    cout << "后序遍历（递归）：\n";
    postorderRecur(head);
    cout << "\n**************\n";
    cout << "后序遍历（非递归）：\n";
    postorderUnRecur(head);
    cout << "\n**************\n";
    return 0;
}