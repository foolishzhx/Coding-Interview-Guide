//2018.12.13
//向有序的环形列表中插入新节点
//
#include <iostream>
#include <vector>
using namespace std;
#define maxsize 15

struct Node
{
public:
    int value;
    Node *next;
    Node():value(NULL), next(NULL){}
};

Node *insertNumToLink(Node *head, int m)
{
    Node *node = new Node;//创建新的节点
    node->value = m;
    if (head == NULL)
    {
        node->next = node;
        return node;
    }    
    Node *pre = head;
    Node *cur = head->next;    
    while (cur != head)
    {
        if (pre->value <= m && cur->value >= m)//确定要插入的位置，插在pre和cur之间
        {           
            break;
        }
        pre = cur;
        cur = cur->next;
    }
    pre->next = node;//while正常退出循环，则插入在头尾之间
    node->next = cur;
    return head->value <= m ? head : node;//相等的时候，插入在头结点后面，依然返回头结点
}

int main()
{
    vector<Node> v1(maxsize);    
    for(int i = 0; i < maxsize; i++)
    {
        v1[i].value = i+1;
        v1[i].next = &v1[i+1];
    }
    v1[maxsize-1].next = &v1[0];
    Node *rst = insertNumToLink(&v1[0], 12);
    return 0;
}