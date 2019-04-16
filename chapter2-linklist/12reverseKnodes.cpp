//2018.12.8
//将单链表的每K个节点之间逆序
//
#include <iostream>
#include <vector>
using namespace std;
#define maxsize 10

class Node
{
public:
    int value;
    Node *next;
    Node():value(NULL), next(NULL){}
};

Node *reverseList(Node *head, Node *tail)
{
    Node *cur = head;
    Node *pre = NULL;
    Node *next = NULL;
    while (cur != tail)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

Node *reverseKnodes(Node *head, int k)
{
    if (k < 2 )//k小于2，没有翻转的意义，故原链表不变
    {
        cout << "k < 2，链表无需调整！" << endl;
        return head;
    }
    if (head == NULL || head->next == NULL)//根据要求，链表长度应该大于等于2
    {
        cerr << "链表长度不符合要求，请重新输入！！" << endl;
        return head;
    }
    Node *cur = head;       Node *next = NULL;
    int count = 0;
    Node *parthead = NULL;      Node *newhead = head;       Node *parttail = NULL;      Node *pretail = NULL;
    while (cur)
    {
        count++;
        next = cur->next;
        parthead = count == 1 ? cur : parthead;        
        if (count == k)
        {
            parttail = reverseList(parthead, next);
            newhead == head ? NULL : pretail->next = parttail;
            newhead = newhead == head ? parttail : newhead;            
            parthead->next = next;
            count = 0;
            pretail = parthead;
        }
        cur = next;
    }
    return newhead;
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
    Node *rst = reverseKnodes(&v1[0], 5);
    return 0;
}