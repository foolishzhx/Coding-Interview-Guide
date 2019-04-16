//
//环形单链表的约瑟夫问题
//
/*
约瑟夫算法理解
 1 2 3 4 5 6 7 8 一共8个人，规定报3的人出局，开始报数

 1 2 3 4 5 6 7 8 n=8,3%8 = 3
 6 7   1 2 3 4 5 n=7,(3%7 + 3)%8 = 6 一层嵌套找到最初位置
 3 4   5 6   1 2 n=6,((3%6 + 3)%7 + 3)%8 = 1 两层
   1   2 3   4 5 n=5,(((3%5 + 3)%6 + 3)%7 + 3)%8 = 5 整除的话求余保留原数
   3   4     1 2 n=4,((((3%4 + 3)%5 +3)%6 +3)%7 + 3)%8 = 2
       1     2 3 n=3,--------------------=8
       1     2   n=2,--------------------=4
             1   n=1,--------------------=7
所以，最后保留下来的就是7号
*/
#include <iostream>
#include <vector>
using namespace std;
#define maxsize 40

class Node
{
public:
    Node *next;
    int value;
    Node():value(NULL), next(NULL){}
};

Node *josephusKill_1(Node *head, int m)
{
    if (m < 1 || head == NULL || head->next == head)
    {
        cout << "请重新输入，不符合要求！" << endl;
        return head;
    }
    Node *last = head;
    while(last->next != head)
    {
        last = last->next;
    }
    Node *cur = head;    Node *pre = last;    Node *next = NULL;
    int count = 0;
    while(cur->next != cur)
    {
        count++;
        next = cur->next;
        if (count == m)
        {
            pre->next = next;
            count = 0;
        }
        else
        {
            pre = cur;
        }
        cur = next;
    }
    return cur;
}

int getlastalive(int num, int m)
{
    if (num == 1)
        return 1;
    return (getlastalive(num-1, m) - 1 + m) % num + 1 ;
}

Node *josephusKill_2(Node *head, int m)
{
    if (m < 1 || head == NULL || head->next == head)
    {
        cout << "请重新输入，不符合要求！！" << endl;
        return head;
    }
    Node *cur = head;
    int length = 1;
    while (cur->next != head)
    {
        length++;
        cur = cur->next;
    }
    int alive = getlastalive(length, m);
    while(alive > 1)
    {
        head = head->next;
        alive--;
    }
    head->next = head;
    return head;
}

int main()
{
    vector<Node> v1(maxsize);
    for (int i = 0; i < maxsize; ++i) {
        v1[i].value = i+1;
        v1[i].next = &v1[i+1];
        if (i == maxsize-1)
            v1[i].next = &v1[0];
    }
    //Node *rst = josephusKill_1(&v1[0], 3);
    Node *rst = josephusKill_2(&v1[0], 3);
    return 0;
}