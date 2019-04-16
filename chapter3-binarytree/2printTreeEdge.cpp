//2018.12.17
//打印二叉树的边界节点
//
#include <iostream>
#include <stack>
#include <queue>
#include "BiTree.h"
using namespace std;

void getTreeEdge(BiTree *cur, int h, vector<vector<BiTree*> > &map)//h=1开始,第0列存储左边界，第1列存储右边界
{
    if (!cur)
        return;
    map[h-1][0] = map[h-1][0] == NULL ? cur : map[h-1][0];//左边界
    map[h-1][1] = cur;//右边界
    getTreeEdge(cur->lchild, h+1, map);
    getTreeEdge(cur->rchild, h+1, map);
}

void getLeftLeaf(BiTree *cur, int h, queue<BiTree*> &map, vector<vector<BiTree*> > &edgeMap, queue<BiTree*> &Map)//得到左半部的叶节点,存储方式为二叉树从上至下最靠左的节点先存储，即描写边界的顺序
{
    if (!cur)
        return;
    if (cur->lchild == NULL && cur->rchild == NULL)
    {
        map.push(cur);
        if (cur == edgeMap[h-1][0])
            Map.push(cur);
        return;
    }
    getLeftLeaf(cur->lchild, h+1, map, edgeMap, Map);
    getLeftLeaf(cur->rchild, h+1, map, edgeMap, Map);
}

void getRightLeaf(BiTree *cur, int h, queue<BiTree*> &map, vector<vector<BiTree*> > &edgeMap, queue<BiTree*> &Map)//得到右半部的叶节点，存储方式为二叉树从上至下最靠左的节点先存储，即描写边界的顺序
{
    if (!cur)
        return;
    if (cur->lchild == NULL && cur->rchild == NULL)
    {
        map.push(cur);
        if (cur == edgeMap[h-1][1])
            Map.push(cur);
        return;
    }
    getRightLeaf(cur->rchild, h+1, map, edgeMap, Map);
    getRightLeaf(cur->lchild, h+1, map, edgeMap, Map);
}

/*两个标准均是逆时针打印
 *打印标准1
 *头节点为边界节点
 *叶节点为边界节点
 *节点所在层是最左或最右，则为边界节点
*/
void printTreeEdge_std1(BiTree *head)
{
    int height = getTreeHeight(head, 1);
    vector<vector<BiTree*> > edge(height, vector<BiTree*>(2));
    getTreeEdge(head,1,edge);//获取左右边界节点，包括叶节点，
    queue<BiTree*> leftEdgeAndLeaf;
    queue<BiTree*> leftLeaf;//包括又是边界又是叶的节点
    getLeftLeaf(head->lchild, 2, leftLeaf, edge, leftEdgeAndLeaf);
    queue<BiTree*> rightEdgeAndLeaf;
    queue<BiTree*> rightLeaf;//包括又是边界又是叶的节点
    getRightLeaf(head->rchild, 2, rightLeaf, edge, rightEdgeAndLeaf);
    cout << "树的边界是：（标准1）\n";
    cout << head->value << "  ";
    for(int i = 1; i < height; i++)//打印左半部分
    {
        cout << edge[i][0]->value << "  ";
        if (leftLeaf.front() == edge[i][0])
        {
            leftEdgeAndLeaf.pop();
            leftLeaf.pop();
            while (!leftLeaf.empty() && !leftEdgeAndLeaf.empty() && leftLeaf.front() != leftEdgeAndLeaf.front())
            {
                cout << leftLeaf.front()->value << "  ";
                leftLeaf.pop();
            }
            if (leftEdgeAndLeaf.empty()) 
            {
                while(!leftLeaf.empty())
                {
                    cout << leftLeaf.front()->value << "  ";
                    leftLeaf.pop();
                }
            }
        }
    }
    stack<int> st;//存储右边边界
    for(int i = 1; i < height ; i++)//打印右半部分
    {
        if (edge[i][0] != edge[i][1])
            st.push(edge[i][1]->value);
        if (rightLeaf.front() == edge[i][1])
        {
            rightEdgeAndLeaf.pop();
            rightLeaf.pop();
            while (!rightLeaf.empty() && !rightEdgeAndLeaf.empty() && rightLeaf.front() != rightEdgeAndLeaf.front())
            {
                st.push(rightLeaf.front()->value);
                rightLeaf.pop();
            }
            if (rightEdgeAndLeaf.empty()) 
            {
                while(!rightLeaf.empty())
                {
                    st.push(rightLeaf.front()->value);
                    rightLeaf.pop();
                }
            }
        }
    }
    while(!st.empty())
    {
        cout << st.top() << "  ";
        st.pop();
    }
    cout << endl;
}

/*打印标准2
 *头节点为边界节点
 *叶节点为边界节点
 *树左边界延伸下来的路径为边界节点
 *树右边界延伸下来的路径为边界节点
*/
void printTreeEdge_std2(BiTree *head)
{
    int height = getTreeHeight(head, 1);
    int leftHeight = getTreeHeight(head->lchild, 1);//左子节点深度
    int rightHeight = getTreeHeight(head->rchild, 1);//右子节点深度
    vector<vector<BiTree*> > edge(height, vector<BiTree*>(2));
    getTreeEdge(head,1,edge);//获取左右边界节点，包括叶节点，
    queue<BiTree*> leftEdgeAndLeaf;
    queue<BiTree*> leftLeaf;//包括又是边界又是叶的节点
    getLeftLeaf(head->lchild, 2, leftLeaf, edge, leftEdgeAndLeaf);
    queue<BiTree*> rightEdgeAndLeaf;
    queue<BiTree*> rightLeaf;//包括又是边界又是叶的节点
    getRightLeaf(head->rchild, 2, rightLeaf, edge, rightEdgeAndLeaf);
    cout << "树的边界是：（标准2）\n";
    cout << head->value << "  ";
    for(int i = 1; i < height; i++)//打印左半部分
    {
        if (edge[i][0] == leftEdgeAndLeaf.front())
            break;
        cout << edge[i][0]->value << "  ";
    }
    while (!leftEdgeAndLeaf.empty())
    {
        cout << leftEdgeAndLeaf.front()->value << "  ";
        leftEdgeAndLeaf.pop();
        leftLeaf.pop();
        while (!leftLeaf.empty() && !leftEdgeAndLeaf.empty() && leftLeaf.front() != leftEdgeAndLeaf.front())
            leftLeaf.pop();        
    }
    if (leftHeight == rightHeight)//深度相同才会打印在最后一层的叶子节点
    {
        while (!leftLeaf.empty())
        {
            cout << leftLeaf.front()->value << "  ";
            leftLeaf.pop();
        }
    }
    stack<int> st;//存储右边边界
    for(int i = 1; i < height; i++)//打印右半部分
    {
        if (edge[i][1] == rightEdgeAndLeaf.front())
            break;
        if (edge[i][0] != edge[i][1])
            st.push(edge[i][1]->value); 
    }
    while (!rightEdgeAndLeaf.empty())
    {
        st.push(rightEdgeAndLeaf.front()->value);
        rightEdgeAndLeaf.pop();
        rightLeaf.pop();
        while (!rightLeaf.empty() && !rightEdgeAndLeaf.empty() && rightLeaf.front() != rightEdgeAndLeaf.front())
            rightLeaf.pop();        
    }
    if (leftHeight == rightHeight)
    {
        while (!rightLeaf.empty())
        {
            st.push(rightLeaf.front()->value);
            rightLeaf.pop();
        }
    }
    while(!st.empty())
    {
        cout << st.top() << "  ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    BiTree *head = setTree();
    printTreeEdge_std1(head);
    printTreeEdge_std2(head);
    return 0;
}
//teststr1 = 1d2r4d7n8r11d13n14n3d5d9l12d15n16n10n6n
/*          
            1
    2              3
       4        5     6
     7   8     9  10
         11   12
       13 14 15 16
*/
//teststr2 = 1d2d4d6l8r9n7d10n11n5r12r13l14r15d16d17n18n19r20r21n3d22n23l24n
/*
                        1
            2                           3
        4       5               22              23
    6       7       12                      24
8        10   11        13
    9               14
                        15
                    16      19
                17      18      20
                                    21
*/
//teststr2 = 1d2d3l4n5n6d7d9l13r14l21l22r23n10r15n8d11n12d16l18n17r19l20n
/*
                        1
            2                    6
        3       5        7               8
    4                 9     10      11      12
                   13         15         16    17
                     14                18        19
                   21                          20
                 22
                   23
*/