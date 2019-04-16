#pragma once
#include <iostream>
using namespace std;

#define maxsize 20
struct BiTree
{
public:
    int value;
    BiTree *lchild;
    BiTree *rchild;
    BiTree():value(NULL), lchild(nullptr), rchild(nullptr){}
};

BiTree *createTreeNode(char *&str);//利用字符串创建二叉树
BiTree *setTree();//创建二叉树
int getTreeHeight(BiTree *head, int height);//获得树的深度

