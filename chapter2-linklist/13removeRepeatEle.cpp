//2018.12.10
//删除无序单链表中值重复出现的节点
//
#include <iostream>
#include <vector>
#include <hash_set>
#include <stdio.h>
using namespace std;
using namespace __gnu_cxx;
#define maxsize 3000
#define rand(a,b) (rand()%(b-a+1)+a)
struct Node
{
public:
    int value;
    Node *next;
    Node():value(NULL), next(NULL){}
};

Node *removeRepeatEle_1(Node *head)//使用hash_set，时间复杂度O(n)，空间复杂度O(n)
{
    if (head == NULL)
        return NULL;
    hash_set<int> set;
    Node *pre = head;
    Node *cur = head->next;
    set.insert(head->value);
    while (cur)
    {
        if (set.find(cur->value) != set.end())//找到重复的节点
        {
            pre->next = cur->next;
        }
        else
        {
            set.insert(cur->value);
            pre = cur;
        }
        cur = pre->next;
    }
    return head;
}

Node *removeRepeatEle_2(Node *head)//每次都是从都到尾遍历，时间复杂度最大O(n^2)，空间复杂度O(1)
{
    if (head == NULL)
        return NULL;
    Node *pre = head;
    Node *cur = pre->next;
    Node *next = NULL;
    Node *h = head;//头节点移动标记
    while(h)
    {        
        while(cur)
        {
            next = cur->next;
            if (cur->value == h->value)
            {
                pre->next = next;
                cur = next;
            }
            else
            {
                pre = cur;
                cur = next;
            }
        }
        h = h->next;
        pre = h;
        cur = pre == NULL ? NULL : pre->next;
    }
    return head;
}


int main()
{
    vector<Node> v1(maxsize);    
    for(int i = 0; i < maxsize; i++)
    {
        v1[i].value = rand(13,16);
        v1[i].next = &v1[i+1];
    }
    v1[maxsize-1].next = NULL;
    //Node *rst = removeRepeatEle_1(&v1[0]);
    Node *rst = removeRepeatEle_2(&v1[0]);
    cout << rst->value;
   return 0;
}