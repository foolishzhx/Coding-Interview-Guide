//2018.12.20
//如何较为直观的打印二叉树
//
#include "BiTree.h"
#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

int length(int a, int len)//返回整数的长度，len默认输入1
{
    if (a < 10)
        return len;
    return length(a/10, len+1);
}

void printSpace(int num)
{
    for (int i = 0; i < num; ++i)
        cout << " ";
}

void printLayerOrder(BiTree *head)//层序遍历
{
    int height = getTreeHeight(head, 1);
    int width =(int) pow(2, height-1)*6;//6代表最后一层每个节点所占字节数
    queue<BiTree*> q;
    q.push(head);
    double count = 0;//每层打印的节点个数
    for (int i = 0; i < height; ++i)
    {
        count = pow(2, i);//2的i次方
        while (count > 0)
        {
            if (q.front()->value)//打印有值节点
            {
                int l = length(q.front()->value, 1);
                printSpace(width /(int) pow(2 , i + 1));
                cout << q.front()->value;
                printSpace((int) ceil(width / pow(2 , i + 1)) - l);
                q.front()->lchild == NULL ? q.push(new BiTree) : q.push(q.front()->lchild);
                q.front()->rchild == NULL ? q.push(new BiTree) : q.push(q.front()->rchild);
                q.pop();
            }
            else//打印无值节点
            {
                printSpace(width/(int) pow(2,i));
                q.push(new BiTree); q.push(new BiTree);
                q.pop();
            }
            count--;
        }
        cout << "\n\n";
    }
}

int main()
{
    printLayerOrder(setTree());
    return 0;
}