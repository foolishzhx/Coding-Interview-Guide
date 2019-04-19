#pragma once
#include <iostream>
using namespace std;

class BiTree
{
private:
    int value;
    BiTree* lchild;
    BiTree* rchild;
public:
    BiTree():value(NULL), lchild(nullptr), rchild(nullptr){}
    int getValue();
    void setLchild(BiTree *node);
    void setRchild(BiTree *node);
    BiTree* getLchild();
    BiTree* getRchild();
    void setValue(int n);
};

BiTree* createTreeNode(char* &str);//利用字符串创建二叉树
BiTree* setTree();//创建二叉树
int getTreeHeight(BiTree* head, int height);//获得树的深度

