//2018.12.24
//二叉树的序列化和反序列化
//
#include <BiTree.h>
#include <iostream>
#include <string>
using namespace std;

void serializeByPre(BiTree *head, string &rst)//先序遍历方法
{
    if (!head)
    {
        rst.append("#!");
        return;
    }
    rst.append(to_string((long long)head->value));
    rst.push_back('!');
    serializeByPre(head->lchild, rst);
    serializeByPre(head->rchild, rst);
}

BiTree* DeserializeByPre(char *&str)
{
    if (*str == '#')//空树或者是空节点
    {
        str++;
        str++;
        return NULL;
    }
    int val = 0;
    while (*str != '!')
    {
        val = 10 * val + (*str - '0');//取相对值
        str++;
    }
    str++;
    BiTree *head = new BiTree;
    head->value = val;
    head->lchild = DeserializeByPre(str);
    head->rchild = DeserializeByPre(str);
    return head;
}

int main()
{
    BiTree *head = setTree();
    string rst;
    serializeByPre(head, rst);
    cout << rst << "\n";
    char *ch = &rst[0];
    BiTree *root = DeserializeByPre(ch);
    return 0;
}