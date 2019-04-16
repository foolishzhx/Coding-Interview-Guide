//
//将单向链表按某值划分成左边小、中间等、右边大的形式
//
#include <iostream>
#include <vector>
using namespace std;
#define maxsize 20

class Node
{
public:
    Node *next;
    int value;
    Node():value(NULL), next(NULL){}
};

Node *reAdjustmentLinklist(Node *head, int m)
{
    if (head == NULL || head->next == NULL)
    {
        cout << "链表有问题，请重新输入！！" << endl;
        return head;
    }
    Node *cur = head;    Node *pre = NULL;    Node *next = NULL;
    Node *mid = NULL;    Node *left = NULL;    Node *right = NULL;
    Node *Mid = NULL;    Node *Left = NULL;    Node *Right = NULL;//每段的头节点
    while (cur != NULL)
    {
        next = cur->next;

        if (cur->value < m)//左边
        {
            if (left == NULL)
            {
                left = cur;
                Left = left;
            }
            else
            {
                left->next = cur;
                left = left->next;
            }
        }
        else if (cur->value > m)//右边
        {
            if (right == NULL)
            {
                right = cur;
                Right = right;
            }
            else
            {
                right->next = cur;
                right = right->next;
            }
        }
        else//中间
        {
            if (mid == NULL)
            {
                mid = cur;
                Mid = mid;
            }
            else
            {
                mid->next = cur;
                mid = mid->next;
            }
        }
        pre = cur;
        cur = next;
    }
    //拼接三块链表
    if (Left == NULL)
    {
        if (Mid == NULL)
        {
            head = Right;
            right->next = NULL;
        }
        else
        {
            mid->next = Right;
            if (right)
                right->next = NULL;
            head = Mid;
        }
    }
    else if (Mid == NULL)
    {
        left->next = Right;
        if (right)
            right->next = NULL;
        head = Left;
    }
    else if (Right == NULL)
    {
        left->next = Mid;
        mid->next = NULL;
        head = Left;
    }
    else
    {
        left->next = Mid;
        mid->next = Right;
        right->next = NULL;
        head = Left;
    }
    return head;
}

int main()
{
    vector<Node> v1(maxsize);
    int arr1[9] = {3,9,8,0,1,4,6,5,3};
    for (int i = 0; i < 9; ++i)
    {
        v1[i].value = arr1[i];
        v1[i].next = i == 8 ? NULL : &v1[i+1];
    }
    Node *rst = reAdjustmentLinklist(&v1[0], 10);
    return 0;
}