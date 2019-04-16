//2019.4.15
//在二叉树中找到累加和为指定值的最长路径长度
//
#include "BiTree.h"
#include <iostream>
#include <algorithm>
#include <map>

int preOrder(BiTree* cur, int goal, int maxLen, int preSum, int level, map<int,int>& sum2level)
{
    if (cur == NULL)
        return maxLen;
    int curSum = preSum + cur->value;
    if (sum2level.find(curSum) == sum2level.end())
        sum2level[curSum] = level;
    if (sum2level.find(curSum - goal) != sum2level.end())
        maxLen = std::max(maxLen, level - sum2level[curSum - goal]);
    maxLen = preOrder(cur->lchild, goal, maxLen, curSum, level + 1, sum2level);
    maxLen = preOrder(cur->rchild, goal,maxLen, curSum, level + 1, sum2level);

    //这一步很关键，每当遍历完叶节点之后，要把和的数据删除，以免影响其他枝叶上寻找最大长度时受到该叶节点的影响
    if (sum2level[curSum] == level)
        sum2level.erase(curSum);
    return maxLen;
}

int getMaxLength(BiTree* head, int goal)
{
    map<int, int> sum2level;//key为求和结果 value为最后一个数字所在的层数
    sum2level[0] = 0;
    return preOrder(head, goal, 0, 0, 1, sum2level);
}

int main()
{
    BiTree *head = setTree();
    std::cout << "请输入要找寻的路径累加和\n";
    int goal;
    std::cin >> goal;
    int maxlen = getMaxLength(head, goal);
    std::cout << "满足条件的最大长度为" << maxlen << std::endl;
    return 0;
}
/*
-3d3d10n0d1n6n9d2n1n
 */

