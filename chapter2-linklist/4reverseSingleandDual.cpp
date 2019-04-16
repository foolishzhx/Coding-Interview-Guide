//
//反转单向链表和双向链表
//
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
#define maxsize 20
class singleNode
{
public:
    int value;
    singleNode *next;
    singleNode():value(NULL), next(NULL){}
};

class doubleNode
{
public:
    int value;
    doubleNode *next;
    doubleNode *pre;
    doubleNode():value(NULL), next(NULL), pre(NULL){}
};

singleNode *reverseSingleLink(singleNode *head)
{
    singleNode *cur = head;
    singleNode *pre = NULL;
    singleNode *next = NULL;
    while(cur)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

doubleNode *reverseDoubleLink(doubleNode *head)
{
    doubleNode *cur = head;
    doubleNode *pre = NULL;
    doubleNode *next = NULL;
    while(cur)
    {
        next = cur->next;
        cur->next = pre;
        cur->pre = next;
        pre = cur;
        cur = next;
    }
    return pre;
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
    singleNode *head1 = reverseSingleLink(&v1[0]);
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
    doubleNode *head2 = reverseDoubleLink(&v2[0]);
    return 0;
}