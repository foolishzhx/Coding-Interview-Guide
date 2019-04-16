//
//反转部分链表
//
#include <iostream>
#include <vector>
using namespace std;
#define maxsize 20
class Node
{
public:
    int value;
    Node *next;
public:
    Node():value(NULL), next(NULL){}
};

Node *reversePartLinklist(Node *head, int from, int to)
{
    if (from >= to || head->next == NULL)
    {
        cout << "请重新输入，有问题" << endl;
        return head;
    }
    Node *cur = head;
    Node *frompre = NULL;
    Node *tonext = NULL;
    int len = 0;
    while(cur)
    {
        len++;
        frompre = len == (from -1) ? cur : frompre;
        tonext = len == (to + 1) ? cur : tonext;
        cur = cur->next;
    }
    if (to > len || from < 1)
    {
        cout << "请重新输入，有问题！" << endl;
        return head;
    }

    cur = frompre == NULL ? head : frompre->next;
    Node *pre = frompre;
    Node *next = NULL;
    while (cur != tonext)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    if (frompre == NULL)
    {
        head->next = tonext;
        head = pre;
    }
    else
    {
        frompre->next->next = tonext;
        frompre->next = pre;
    }
    return head;
}

int main()
{
    vector<Node> v1(maxsize);
    int arr1[9] = {1,2,3,4,5,6,7,8,9};
    for (int i = 0; i < 9; ++i)
    {
        v1[i].value = arr1[i];
        v1[i].next = i == 8 ? NULL : &v1[i+1];
    }
    Node *head = reversePartLinklist(&v1[0], 1, 9);
    return 0;
}
