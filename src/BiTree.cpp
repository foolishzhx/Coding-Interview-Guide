#include "../include/BiTree.h"
#include <string>

int BiTree::getValue()
{
    return this->value;
}

BiTree* BiTree::getLchild()
{
    return this->lchild;
}

BiTree* BiTree::getRchild()
{
    return this->rchild;
}

void BiTree::setValue(int n)
{
    this->value = n;
}

void BiTree::setLchild(BiTree *node)
{
    this->lchild = node;
}

void BiTree::setRchild(BiTree *node)
{
    this->rchild = node;
}

BiTree* createTreeNode(char* &str)//创建二叉树，d代表双节点，l代表左节点，r代表右节点，n代表无节点。输入双节点时，先输入左节点，后输入右节点
{
    bool negative = false;
    if (*str == '-')
    {
        negative = true;
        str++;
    }
    if (*str < '0' || *str > '9')
    {
        cout << "输入的字符串有问题，请重新输入！" << endl;
        return NULL;
    }
    int val = 0;
    while (*str >= '0' && *str <= '9')
    {
        val = 10 * val + (*str - '0');//取相对值
        str++;
    }
    if (negative)
        val = -val;
    BiTree *head = new BiTree;
    head->setValue(val);
    if (*str == 'd')
    {
        str++;
        head->setLchild(createTreeNode(str));
        head->setRchild(createTreeNode(str));
    }
    else if (*str == 'l')
    {
        str++;
        head->setLchild(createTreeNode(str));
    }
    else if (*str == 'r')
    {
        str++;
        head->setRchild(createTreeNode(str));
    }
    else if (*str == 'n')
    {
        str++;
    }
    else
        cerr << "输入的字符串有问题" << endl;
    return head;
}

BiTree* setTree()
{
    cout << "按照先序遍历输入树节点字符串:（按照int+l/r/d/n格式，例如1d2n3n）" << endl;
    string str;
    cin >> str;
    char *ch = &str[0];
    BiTree *head = createTreeNode(ch);
    return head;
}

int getTreeHeight(BiTree* head, int height)//输入头结点，以及height=1
{
    if (!head)
        return height-1;
    return max(getTreeHeight(head->getLchild(), height+1), getTreeHeight(head->getRchild(), height+1));
}

