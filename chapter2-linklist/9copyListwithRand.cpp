//2018.12.6
//复制带有随机指针的链表
//

#include <iostream>
#include <map>
#include <stdio.h>
#include <vector>
#include <algorithm>//使用shuffle函数
using namespace std;

#define maxsize 10
#define rnd(a,b) (rand()%(b-a+1)+a)//生成a到b之间的随机整数
class Node
{
public:
    int value;
    Node *next;
    Node *rand;
public:
    Node():value(NULL), next(NULL), rand(NULL){}
};

Node *copyListwithRand_1(Node *head)//用map容器存储新节点，空间复杂度O(n)
{   
    if (head->next == NULL || head->next->next == NULL)
    {
        cerr << "链表节点不符合要求，请重新输入！" << endl;
    }    
    map<Node*, Node*> nodemap;
    Node *cur = head;
    while (cur)
    {
        nodemap.insert(pair<Node*, Node*>(cur, new Node));
        nodemap.find(cur)->second->value = cur->value;
        //nodemap.find(cur)->second->next = NULL;
        //nodemap.find(cur)->second->rand = NULL;
        cur = cur->next;
    }

    cur = head;
    while (cur)
    {
        nodemap.find(cur)->second->next = cur->next != NULL ? nodemap.find(cur->next)->second : NULL;
        nodemap.find(cur)->second->rand = cur->rand != NULL ? nodemap.find(cur->rand)->second : NULL;
        cur = cur->next;
    }
    return nodemap.find(head)->second;   
}

Node *copyListwithRand_2(Node *head)
{
    if (head->next == NULL || head->next->next == NULL)
    {
        cerr << "链表节点不符合要求，请重新输入！" << endl;
    }
    Node *cur = head;
    Node *next = NULL;
    while (cur)//复制节点
    {
        next = cur->next;
        cur->next = new Node;
        cur->next->value = cur->value;
        cur->next->next = next;
        cur = next;
    }
    cur = head;
    Node *curCopy = NULL;
    while (cur)//设置随机节点
    {
        next = cur->next->next;
        curCopy = cur->next;
        curCopy->rand = cur->rand != NULL ? cur->rand->next : NULL; 
        cur = next;
    }
    Node *res = head->next;
    cur = head;
    while (cur)//拆分链表
    {
        next = cur->next->next;
        curCopy = cur->next;
        cur->next = next;
        curCopy->next = next != NULL ? next->next : NULL;
        cur = next;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> v1(maxsize);    
    for(int i = 0; i < maxsize; i++)
    {
        v1[i] = i;
    }
    int count = 1;
    while (count)//生成没有自己指向自己的随机指针数组
    {
        count = 0;
        random_shuffle(v1.begin(), v1.end());
        for(int i = 0; i < maxsize; i++)
        {
            if (v1[i] == i)
            {
                count++;
                break;
            }
        }        
    }    

    vector<Node> v2(maxsize);    
    for(int i = 0; i < maxsize; i++)
    {
        v2[i].value = i + 1;
        v2[i].next = &v2[i+1];
        if (v1[i] == 0)
            v2[i].rand = NULL;
        else
            v2[i].rand = &v2[v1[i]];
    }
    v2[maxsize-1].next = NULL;
    //Node *head = copyListwithRand_1(&v2[0]);
    Node *head = copyListwithRand_2(&v2[0]);
    return 0;
}
