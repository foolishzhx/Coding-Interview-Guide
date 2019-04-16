//2018.12.7
//两个单向链表相交的一系列问题
//
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
#define maxsize 10

class Node
{
public:
    int value;
    Node *next;
public:    
    Node():value(NULL), next(NULL){}

private:
Node *getLoopNode(Node *head)//获取链表进环的第一个节点，无环的话返回NULL
{
    if (head == NULL || head->next == NULL || head->next->next == NULL)
        return NULL;
    Node *slow = head;
    Node *fast = head;
    while (1)//链表有无环
    {
        if (fast && fast->next)
            fast = fast->next->next;
        else//无环直接返回NULL
        {
            return NULL;
            break;
        }
        slow = slow->next;
        if (slow == fast)//第一次相遇
        {
            break;
        }
    }
    fast = head;
    while (1)//寻找入环节点
    {
        if (fast == slow)
            break;
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

private:
int getListLength(Node *head, Node *tail)//获取链表长度
{
    int length = 0;
    Node *cur = head;
    while (cur != tail)
    {
        length++;
        cur = cur->next;
    }
    return length;
}

//使用的方法：将长的链表移动长度差的距离，然后同时移动两个链表，找到第一个相等的节点
private:
Node *getNoLoopIntersectNode(Node *head1, Node *tail1, Node *head2, Node *tail2)//无环链表寻找交点,若是单向链表 tail = NULL
{
    int len1 = getListLength(head1, tail1);
    int len2 = getListLength(head2, tail2);
    int delta = len1 - len2;
    Node *cur1 = head1;
    Node *cur2 = head2;
    if (delta > 0)//len1 > len2
    {
        while (delta)
        {
            cur1 = cur1->next;
            delta--;
        }
        while (cur1 != tail1 && cur1 != cur2)
        {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
    }
    else if (delta < 0)//len1 < len2
    {
        while (abs(delta))
        {
            cur2 = cur2->next;
            delta++;
        }
        while (cur1 != tail1 && cur1 != cur2)
        {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
    }
    else//len1 = len2
    {
        while (cur1 != tail1 && cur1 != cur2)
        {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
    }
    if (cur1 == NULL)//整个单链表无交点
        return NULL;
    else if (cur1->value != cur2->value)//局部单链表无交点
        return NULL;
    else//链表有交点
        return cur1;
}

//有环链表相交分为三种情况
//1、在无环部分相交
//2、在入环节点相交
//3、在环部相交，但入环节点不同
private:
Node *getLoopIntersectNode(Node *head1, Node *loop1, Node *head2, Node *loop2)//有环链表寻找交点
{
    Node *rst = getNoLoopIntersectNode(head1, loop1, head2, loop2);//检查是否有情况1发生，即在无环部分相交
    if (rst && rst != loop1)//无环部分有交点，返回该节点，后面部分全相交
    {
        cout << "满足情况1，在单链表部分相交" << endl;
        return rst;

    }
    if (loop1 == loop2)//检查是否有情况2发生，即在环入口相交，返回该节点
    {
        cout << "满足情况2，在入环节点相交" << endl;
        return loop1;
    }
    Node *cur1 = loop1;
    Node *cur2 = loop2;
    while (1)//检查是否有情况3发生，即在环部相交，但入口不同,如果有返回任何一个入口，没有返回NULL
    {
        if(cur1 == cur2)
        {
            rst = loop1;
            cout << "满足情况3，在环部分相交，入环节点不同" << endl;
            break;
        }
        cur1 = cur1->next;
        if (cur1 == loop1)
        {
            rst = NULL;
            break;
        }
    }
    return rst;
}

public:
Node *getIntersectNode(Node *head1, Node *head2)
{
    Node *loop1 = getLoopNode(head1);
    Node *loop2 = getLoopNode(head2);
    Node *rst = NULL;
    cout << "两个链表的检测结果为：";
    if (loop1 == NULL && loop2 == NULL)//均为无环链表
    {   
        cout << "两个链表均为无环链表" << endl; 
        rst = getNoLoopIntersectNode(head1, loop1, head2, loop2);
        cout << "相交结果为：";
        rst == NULL ? cout << "无相交节点" : cout << "有相交节点，节点值是： " << rst->value;
        cout << "\n" << "检测完毕！！\n" << endl;
    }
    else if (loop1 && loop2)//均为有环链表
    {
        cout << "两个链表均为有环链表" << endl; 
        cout << "第一个链表的入环节点是：" << loop1->value << endl;
        cout << "第二个链表的入环节点是：" << loop2->value << endl;
        rst = getLoopIntersectNode(head1, loop1, head2, loop2);
        cout << "相交结果为：";
        rst == NULL ? cout << "无相交节点" : cout << "节点值是： " << rst->value;
        cout << "\n" << "检测完毕！！\n" << endl;
    }
    else//一个有环一个无环，不可能相交
    {
        cout << "两个链表一个无环，一个有环，无相交节点" << endl; 
        cout << "相交结果为：";
        rst = NULL;
        cout << "无相交节点";
        cout << "\n" << "检测完毕！！\n" << endl;
    }   
    return rst;
}
};

int main()
{
    //第一种 两个无环不相交
    vector<Node> v1(maxsize);    vector<Node> v2(maxsize);
    for(int i = 0; i < maxsize; i++)
    {
        v1[i].value = i + 1;        v2[i].value = i + 11;
        v1[i].next = &v1[i+1];      v2[i].next = &v2[i+1];
    }
    v1[maxsize-1].next = NULL;    v2[maxsize-1].next = NULL;
    Node *rst1 = NULL;    rst1->getIntersectNode(&v1[0], &v2[0]);
    cout << "**********\n" << endl;
    //第二种 两个无环相交
    vector<Node> v3(maxsize);    vector<Node> v4(maxsize);
    for(int i = 0; i < maxsize; i++)
    {
        v3[i].value = i + 1;        v4[i].value = i + 11;
        v3[i].next = &v3[i+1];      v4[i].next = &v4[i+1];
    }
    v3[maxsize-1].next = NULL;    v4[maxsize-1].next = NULL;
    v4[5].next = &v3[5];//设置相交节点
    Node *rst2 = NULL;    rst2->getIntersectNode(&v3[0], &v4[0]);
    cout << "**********\n" << endl;
    //第三种 两个有环不相交
    vector<Node> v5(maxsize);    vector<Node> v6(maxsize);
    for(int i = 0; i < maxsize; i++)
    {
        v5[i].value = i + 1;        v6[i].value = i + 11;
        v5[i].next = &v5[i+1];      v6[i].next = &v6[i+1];
    }
    v5[maxsize-1].next = &v5[5];    v6[maxsize-1].next = &v6[5];//设置入环节点
    Node *rst3 = NULL;    rst3->getIntersectNode(&v5[0], &v6[0]);
    cout << "**********\n" << endl;
    //第四种 两个有环相交 情况1
    vector<Node> v7(maxsize);    vector<Node> v8(maxsize);
    for(int i = 0; i < maxsize; i++)
    {
        v7[i].value = i + 1;        v8[i].value = i + 11;
        v7[i].next = &v7[i+1];      v8[i].next = &v8[i+1];
    }
    v7[maxsize-1].next = &v7[5];    v8[maxsize-1].next = &v8[7];//设置入环节点
    v7[2].next = &v8[3];
    Node *rst4 = NULL;    rst4->getIntersectNode(&v7[0], &v8[0]);
    cout << "**********\n" << endl;
    //第五种 两个有环相交 情况2
    vector<Node> v9(maxsize);    vector<Node> v10(maxsize);
    for(int i = 0; i < maxsize; i++)
    {
        v9[i].value = i + 1;        v10[i].value = i + 11;
        v9[i].next = &v9[i+1];      v10[i].next = &v10[i+1];
    }
    v9[maxsize-1].next = &v9[5];    v10[maxsize-1].next = &v10[5];//设置入环节点
    v9[5].next = &v10[5];
    Node *rst5 = NULL;    rst5->getIntersectNode(&v9[0], &v10[0]);
    cout << "**********\n" << endl;
    //第六中 两个有环相交 情况3
    vector<Node> v11(maxsize);    vector<Node> v12(maxsize);
    for(int i = 0; i < maxsize; i++)
    {
        v11[i].value = i + 1;        v12[i].value = i + 11;
        v11[i].next = &v11[i+1];     v12[i].next = &v12[i+1];
    }
    v11[maxsize-1].next = &v11[6];    v12[maxsize-1].next = &v12[7];//设置入环节点
    v11[5].next = &v12[8];
    Node *rst6 = NULL;    rst6->getIntersectNode(&v11[0], &v12[0]);
    return 0;
}