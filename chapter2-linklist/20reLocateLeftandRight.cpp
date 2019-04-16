//2018.12.14
//按照左右半区的方式重新组合单链表
//
#include <iostream>
#include <vector>
using namespace std;
#define maxsize 6

struct Node
{
public:
    int value;
    Node *next;
    Node():value(NULL), next(NULL){}
};

Node *reLocateLdeftandRight(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        cerr << "该链表过短，请重新输入新的头节点！！\n";
        return head;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *Rhead = fast->next == NULL ? slow : slow->next;//右半边的起始节点
    Node *lcur = head;
    Node *rcur = Rhead;
    Node *lnext = NULL;
    Node *rnext = NULL;
    while (1)
    {
        lnext = lcur->next;
        lnext = lnext == Rhead ? NULL : lnext;
        if (lnext == NULL)
            break;
        rnext = rcur->next;
        lcur->next = rcur;
        rcur->next = lnext;
        lcur = lnext;
        rcur = rnext;
    }
    lcur->next = rcur;
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
    Node *rst = reLocateLdeftandRight(&v1[0]);
    return 0;
}