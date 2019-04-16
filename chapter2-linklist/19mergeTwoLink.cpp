//2018.12.13
//合并两个有序的单链表
//
#include <iostream>
#include <vector>
using namespace std;
#define maxsize 10

struct Node
{
public:
    int value;
    Node *next;
    Node():value(NULL), next(NULL){}
};

Node *mergeTwoLinkRecursively(Node *head1, Node *head2)//使用递归完成合并，但是空间复杂度O(max(m,n))
{
    if (head1 == NULL)
        return head2;
    else if (head2 == NULL)
        return head1;
    Node *cur = NULL;
    if (head1->value < head2->value )
    {
        cur = head1;
        cur->next = mergeTwoLinkRecursively(head1->next, head2); 
    }
    else
    {
        cur = head2;
        cur->next = mergeTwoLinkRecursively(head1, head2->next);
    }
    return cur;
}

Node *mergeTwoLink(Node *head1, Node *head2)//不使用递归合并，空间复杂度O(1)
{
    if (head1 == NULL)
        return head2;
    else if (head2 == NULL)
        return head1;
    Node *head = head1->value < head2->value ? head1 : head2;
    Node *pre = NULL;
    Node *next = NULL;
    Node *cur1 = head == head1 ? head1 : head2;//遍历头节点值较小的链表
    Node *cur2 = head == head2 ? head1 : head2;//遍历头节点值较大的链表
    while (cur1 && cur2)
    {
        if (cur1->value <= cur2->value)
        {
            pre = cur1;
            cur1 = cur1->next;
        }
        else
        {
            next = cur2->next;
            pre->next = cur2;
            cur2->next = cur1;
            pre = cur2;
            cur2 = next;
        }
    }
    pre->next = cur1 == NULL ? cur2 : cur1;
    return head;
}

int main()
{
    vector<Node> v1(maxsize);    
    for(int i = 0; i < maxsize; i++)
    {
        v1[i].value = i + 1;       
        v1[i].next = &v1[i+1];      
    }
    v1[maxsize-1].next = NULL;
    vector<Node> v2(maxsize);
    for(int i = 0; i < maxsize; i++)
    {
        v2[i].value = i*2 + 3;
        v2[i].next = &v2[i+1];
    }    
    v2[maxsize-1].next = NULL;
    //Node *rst = mergeTwoLinkRecursively(&v1[0], &v2[0]);
    Node *rst = mergeTwoLink(&v1[0], &v2[0]);
    return 0;
}
