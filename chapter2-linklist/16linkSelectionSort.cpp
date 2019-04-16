//2018.12.12
//单链表的选择排序
//
#include <iostream>
#include <vector>

using namespace std;
#define maxsize 20

struct Node
{
    public:
    int value;
    Node *next;
    Node():value(NULL), next(NULL){}
};

Node *getPreSmallestNode(Node *head, Node *tail)
{
    Node *cur = head;
    Node *pre = NULL;
    Node *smallest = head;
    Node *Presmallest = NULL;
    while (cur != tail->next)//要检测到tail，所以结束标志为tail.next
    {
        if (cur->value <= smallest->value)
        {
            smallest = cur;
            Presmallest = pre;
        }
        pre = cur;
        cur = cur->next;
    }
    return Presmallest;
}

Node *selectionSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        cout << "无需进行排序！" << endl;
        return head;
    }
    Node *cur = head;
    while (cur->next)
    {
        cur = cur->next;   
    }
    Node *tail = cur;//得到未排序链表的尾节点
    Node *newhead = NULL;
    Node *newtail = NULL;
    Node *pre = NULL;
    Node *small = NULL;
    while (head != newhead)
    {
        pre = getPreSmallestNode(head, tail);
        small = pre == NULL ? head : pre->next;
        small == head ? NULL : pre->next = small->next;//删除最小节点
        head = small == head ? head->next : head;//头节点是最小值，更新头节点
        tail = small == tail ? pre : tail;//尾节点是最小值，更新尾节点
        newhead = newhead == NULL ? small : newhead;//获取新的头结点
        tail == NULL ? NULL : tail->next = newhead;
        newtail = newtail == NULL ? newhead : newtail;
        newtail->next = small;//更新排序好的链表尾部
        newtail = newtail->next;
    }
    newtail->next = NULL;
    return newhead;
}

int main(int argc, char const *argv[])
{
    vector<Node> v1(maxsize);
    int arr1[maxsize] = {9,4,6,7,3,2,4,5,7,9,9,7,5,4,2,1,3,5,6,0};
    for(int i = 0; i < maxsize; i++)
    {
        v1[i].value = arr1[i];        
        v1[i].next = &v1[i+1];      
    }
    v1[maxsize-1].next = NULL;  
    Node *rst = selectionSort(&v1[0]);  
    return 0;
}