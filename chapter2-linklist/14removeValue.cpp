//2018.12.10
//在单链表中删除指定值的节点
//有问题
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
#define maxsize 1000
#define rand(a,b) (rand()%(b-a+1)+a)
struct Node
{
public:
    int value;
    Node *next;
    Node():value(NULL), next(NULL){}
};

Node *removeValue(Node *head, int m) {
    if (head == NULL) {
        cerr << "链表为空，请重新输入！" << endl;
    }
    Node *pre = NULL;
    Node *cur = head;
    Node *next = NULL;
    while (cur) {
        next = cur->next;
        if (cur->value == m) {
            if (cur == head) {//如果删除头节点，则头后移
                head = head->next;
                cur = head;
            } else {//删除的不是头结点，正常删除
                pre->next = next;
                cur = next == NULL ? NULL : next->next;
            }
        } else {//不删除节点，正常后移动
            pre = cur;
            cur = next;
        }
    }
    return head;
}

int main()
{
    vector<Node> v1(maxsize);
    for(int i = 0; i < maxsize; i++)
    {
        v1[i].value = rand(1,10);
        v1[i].next = &v1[i+1];
    }
    v1[maxsize-1].next = NULL;
    Node *rst = removeValue(&v1[0], 4);
    return 0;
}