//2018.12.29
//找到二叉树中的最大搜索二叉子树
//最大搜索二叉树满足以下条件：1该子树的头结点的值大于左子树中的最大值 2该子树的头结点的值小于右子树中的最小值
#include <iostream>
#include "BiTree.h"
#include <stdint.h>
using namespace std;

BiTree *postOrder(BiTree *head, int *record)
{
    if (!head)//叶节点
    {
        record[0] = 0;
        record[1] = INT32_MIN;//最大值设置为最小
        record[2] = INT32_MAX;//最小值设置为最大
        return NULL;
    }
    BiTree *lBST = postOrder(head->lchild, record);
    int lsize = record[0];
    int lmax = record[1];
    int lmin = record[2];
    BiTree *rBST = postOrder(head->rchild, record);
    int rsize = record[0];
    int rmax = record[1];
    int rmin = record[2];
    record[1] = max(rmax, head->value);//求最大值是当前节点值与子节点最大值相比
    record[2] = min(lmin, head->value);//求最小值是当前节点值与子节点最小值相比
    if (lmax < head->value && head->value < rmin && lBST == head->lchild && rBST == head->rchild)
    {
        record[0] = lsize + rsize + 1;
        return head;
    }
    record[0] = max(lsize, rsize);
    return lsize > rsize ? lBST : rBST;
}

BiTree *getBiggestSubBST(BiTree *head)
{
    int record[3];//第一位代表节点个数，第二位代表左子节点最大值，第三位代表右子节点最小值
    return postOrder(head, record);
}

int main()
{
    BiTree *rst = getBiggestSubBST(setTree());
    return 0;
}
//testptr = 6d1d0n3n12d10d4d2n5n14d11n15n13d20n16n
/*
            6
    1               12
0       3       10      13
              4   14   20 16
             2 5 11 15
*/
//testptr = 16d12d4d1n5n14d13n15n29d10d3n18d17n19n34d30n35n
/*
                                16
                12                              29
        4               14              10              34
    1       5       13      15      3       18      30      35
                                          17  19
*/