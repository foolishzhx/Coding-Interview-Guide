//
//删除单链表和双链表倒数第K个元素
//
#include <iostream>
#include <vector>
using namespace std;

#define maxsize 20

class singleNode
{
public:
    singleNode *next;
    int value;
public:
    singleNode():value(NULL),next(NULL){}
};

singleNode *deleteresinglelastKnode(singleNode *head, int K)
{
    if (K <= 0)
    {
        cout << "K的值不符合要求，请重新输入!!!";
        return head;
    }
    singleNode *cur = head;
    int len = 1;
    while(cur->next)
    {
        len++;
        cur = cur->next;
    }
    if (K > len)
    {
        return head;
    }
    else if (K == len)
    {
        head = head->next;
    }
    else
    {
        cur = head;
        for (int i = 0; i < len - K - 1; i++)
        {
            cur = cur->next;
        }
        cur->next = cur->next->next;
    }
    return head;
}

class doubleNode
{
public:
    int value;
    doubleNode *next;
    doubleNode *pre;
public:
    doubleNode():value(NULL), next(NULL), pre(NULL){}
};

doubleNode *deletedoublelastKnode(doubleNode *head, int K)
{
    if(K <= 0)
    {
        cout << "K值不符合要求，请重新输入！" << endl;
        return head;
    }
    doubleNode *cur = head;
    doubleNode *next;
    int len = 1;
    while(cur->next)
    {
        len++;
        cur = cur->next;
    }
    if (K == len)
    {
        head = head->next;
        head->pre = NULL;
    }
    else if (K < len)
    {
        cur = head;
        for (int i = 0; i < len - K - 1; i++)
        {
            cur = cur->next;
        }
        next = cur->next;
        next->next->pre = cur;
        cur->next = cur->next->next;
    }
    return head;
}

int main()
{
    vector<singleNode> v1(maxsize);
    int arr1[10] = {2,5,6,8,7,4,9,12,45,16};
    for (int i = 0; i < 10; ++i)
    {
        v1[i].value = arr1[i];
        v1[i].next = &v1[i+1];
        if (i == 9)
            v1[i].next = NULL; 
    }
    singleNode *singlehead = deleteresinglelastKnode(&v1[0], 1);

    vector<doubleNode> v2(maxsize);
    for (int i = 0; i < 10; ++i)
    {
        v2[i].value = arr1[i];
        v2[i].next = &v2[i+1];
        if (i >= 1)
            v2[i].pre = &v2[i-1];
        if (i == 9)
            v2[i].next = NULL;
    }
    doubleNode *doublehead = deletedoublelastKnode(&v2[0], 10);

    return 0;
}