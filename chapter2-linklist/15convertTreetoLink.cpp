#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>

#define maxsize 20
using namespace std;

struct DualNode//双向链表
{
public:
    int value;
    DualNode *pre, *next;
    DualNode():value(NULL), pre(NULL), next(NULL){}
};

struct BinaryTree//二叉树
{
public:
    int value;
    BinaryTree *leftchild, *rightchild;
    BinaryTree():value(NULL), leftchild(NULL), rightchild(NULL){}
public:
    DualNode *preorder(BinaryTree *head);//前序
    DualNode *inorder(BinaryTree *head);//中序
    DualNode *postorder(BinaryTree *head);//后序
};

DualNode *BinaryTree::preorder(BinaryTree *t)
{
    if (t != NULL)
    {
        
    }
}

DualNode *BinaryTree::inorder(BinaryTree *t)
{

}

DualNode *BinaryTree::postorder(BinaryTree *t)
{

}

DualNode *convertTreetoLink(BinaryTree *head, string option)
{
    if (head == NULL) {cerr << "二叉树为空，请重新输入头结点！" << endl;}
    BinaryTree *cur = head;
    BinaryTree *left = NULL;
    BinaryTree *right = NULL;
    if (option == "preoder")//前序遍历
    {

    }
    else if (option == "inorder")//中序遍历
    {

    }
    else if (option == "postorder")//后序遍历
    {

    }
    else {cerr << "选项有问题，请重新输入!" << endl;}
}

int main()
{



    return 0;
}