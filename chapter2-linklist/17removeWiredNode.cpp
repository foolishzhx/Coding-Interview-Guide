//2018.12.12
//一种怪异的节点删除方式
//给定链表中的一个节点，不给头结点，在链表中删除某一个指定的节点，分析会遇到哪些问题
//问题1：无法删除最后一个节点。使用删除节点的方法实际上是将此节点的值替换成下一个节点的值，然后删除下一个节点。
//      但是最后一个节点下个值是NULL，若要删除最后一个节点，则只能使value变为NULL，而该节点地址不能变为NULL，
//      而且无法找到前一个节点，不能使它的next指向NULL
//问题2：工程上，节点的结构复杂，不是改变一个值那么简单，所以改变value的方法会带来很多麻烦。

#include <iostream>
#include <vector>
#include <stdexcept>
using  namespace std;
#define maxsize 20

struct Node
{
    public:
    int value;
    Node *next;
    Node():value(NULL), next(NULL){}
};

void removeWeirdNode(Node *node)
{
    if (node == NULL) { return; }
    Node *next = node->next;
    if (next == NULL)
        throw runtime_error("不能移除最后一个节点！\n") ;
    node->value = next->value;
    node->next = next->next;
}

int main()
{

    return 0;
}
