//2018.12.25
//Morris遍历二叉树，时间复杂度O（n），空间复杂度O（1）
//
#include <iostream>
#include "BiTree.h"
using namespace std;
/*前序遍历
1. 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点。

2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。

   a) 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。输出当前节点！！！当前节点更新为当前节点的左孩子。

   b) 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空（恢复树的形状）。当前节点更新为当前节点的右孩子。

3. 重复以上1、2直到当前节点为空。*/
void morrisTraversalPreOrder(BiTree *head)//前序遍历
{
    BiTree *pre = NULL;
    BiTree *cur = head;
    while (cur)
    {
        if (cur->lchild == NULL)// 1
        {
            cout << cur->value << "  ";
            cur = cur->rchild;
        }
        else
        {
            pre = cur->lchild;
            while (pre->rchild && pre->rchild != cur)//找到左子树中的最右节点
                pre = pre->rchild;
            if (pre->rchild == NULL)// 2.a
            {
                pre->rchild = cur;
                cout << cur->value << "  ";
                cur = cur->lchild;
            }
            else// 2.b
            {
                pre->rchild = NULL;
                cur = cur->rchild;
            }
        }
    }
}

/*中序遍历
1. 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点。

2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。

   a) 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。当前节点更新为当前节点的左孩子。

   b) 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空（恢复树的形状）。输出当前节点！！！当前节点更新为当前节点的右孩子。

3. 重复以上1、2直到当前节点为空。*/
void morrisTraversalInOrder(BiTree *head)
{
    BiTree *pre = NULL;
    BiTree *cur = head;
    while (cur)
    {
        if (cur->lchild == NULL)// 1
        {
            cout << cur->value << "  ";
            cur = cur->rchild;
        }
        else
        {
            pre = cur->lchild;
            while (pre->rchild && pre->rchild != cur)//找到左子树中的最右节点
                pre = pre->rchild;
            if (pre->rchild == NULL)// 2.a
            {
                pre->rchild = cur;
                cur = cur->lchild;
            }
            else// 2.b
            {
                pre->rchild = NULL;
                cout << cur->value << "  ";
                cur = cur->rchild;
            }
        }
    }
}

/*后序遍历
1. 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点。

2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。

   a) 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。当前节点更新为当前节点的左孩子。

   b) 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空（恢复树的形状）。反转输出前驱节点的左节点的右节点到前驱节点！！！当前节点更新为当前节点的右孩子。

3. 重复以上1、2直到当前节点为空。*/
BiTree *reverseTree(BiTree *from, BiTree *to)
{
    if (from == to)
        return from;
    BiTree *pre = NULL;
    BiTree *cur = from;
    BiTree *next = NULL;
    while (true)
    {
        next = cur->rchild;
        cur->rchild = pre;
        pre = cur;
        if (cur == to || next == NULL)//为了应对尾部为NULL的问题，防止边界溢出
            break;
        cur = next;

    }
    return pre;//如果to=NULL， 更新边界to，使得to！=NULL
}

void printReverseEdge(BiTree *from, BiTree *to)
{
    BiTree *tail =reverseTree(from, to);
    BiTree *cur = tail;
    while (true)
    {
        cout << cur->value << "  ";
        if (cur == from)
            break;
        cur = cur->rchild;
    }
    reverseTree(tail, from);
}

void morrisTraversalPostOrder(BiTree *head)
{
    BiTree *pre = NULL;
    BiTree *cur = head;
    while (cur != NULL)
    {
        if (cur->lchild == NULL)
            cur = cur->rchild;
        else
        {
            pre = cur->lchild;
            while (pre->rchild && pre->rchild != cur)
                pre = pre->rchild;
            if (pre->rchild == NULL)
            {
                pre->rchild = cur;
                cur = cur->lchild;
            }
            else
            {
                printReverseEdge(pre->rchild->lchild, pre);
                pre->rchild = NULL;
                cur = cur->rchild;
            }
        }
    }
    printReverseEdge(head, NULL);
}

int main()
{
    BiTree *head = setTree();
    cout << "前序遍历：\n";
    morrisTraversalPreOrder(head);
    cout << "\n************\n";
    cout << "中序遍历：\n";
    morrisTraversalInOrder(head);
    cout << "\n************\n";
    cout << "后序遍历：\n";
    morrisTraversalPostOrder(head);
    cout << endl;
    return 0;
}