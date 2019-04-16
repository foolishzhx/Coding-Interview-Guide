//
//两个单链表生成相加链表
//
#include <iostream>
#include <vector>
#define maxsize 10
using namespace std;

class Node
{
public:
    Node *next;
    int value;
public:
    Node():value(NULL), next(NULL){}
};

Node *reverseList(Node *head)//翻转链表
{
    Node *cur = head;
    Node *pre = NULL;
    Node *next = NULL;
    while (cur)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

Node *addList(Node *head1, Node *head2)
{
    head1 = reverseList(head1);
    head2 = reverseList(head2);
    Node *c1 = head1;
    Node *c2 = head2;
    Node *c3 = NULL;//求和链表
    Node *head = NULL;//求和链表最低位节点
    int flag = 0;
    while (c1 != NULL || c2 != NULL)
    {
        int value1 = c1 != NULL ? c1->value : 0;
        int value2 = c2 != NULL ? c2->value : 0;
        int value = value1 + value2 + flag;
        flag = value / 10;
        Node *add = new Node;
        add->value = value % 10;
        if (c3 == NULL)
            head = add;
        c3 == NULL ? c3 = add : c3->next = add;
        c3 = c3->next == NULL ? c3 : c3->next;
        c1 = c1 != NULL ? c1->next : c1;
        c2 = c2 != NULL ? c2->next : c2;
    }
    if (flag == 1)
    {
        Node *add = new Node;
        add->value = flag;
        c3->next = add;
    }
    head = reverseList(head);
    head1 = reverseList(head1);
    head2 = reverseList(head2);
    return head;
}

int main()
{
    vector<Node> v1(maxsize);
    int arr1[6] = {2,4,7,4,5,6};
    for (int i = 0; i < 6; ++i)
    {
        v1[i].value = arr1[i];
        v1[i].next = i == 5 ? NULL : &v1[i+1];
    }
    vector<Node> v2(maxsize);
    int arr2[6] = {8,7,6,5,4,4};
    for (int i = 0; i < 6; ++i)
    {
        v2[i].value = arr2[i];
        v2[i].next = i == 5 ? NULL : &v2[i+1];
    }
    Node *head = addList(&v1[0], &v2[0]);
    return 0;
}