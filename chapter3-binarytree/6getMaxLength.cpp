//2019.4.15
//在二叉树中找到累加和为指定值的最长路径长度 时间复杂度O(n),空间复杂度O(h)
//
#include "BiTree.h"
#include <iostream>
#include <algorithm>
#include <map>
/*
 * 本道题的主要解决办法采用了map，使得检测累计和时方便快速很多
 * 核心思想和书里的一样，接下来说下自己的理解
 * 首先要遍历整个二叉树，所以先想到的就是遍历方法，即递归先序遍历
 * 之后，map存放第一个kv对0,0
 * preOrder里的变量解析：goal是累加和目标值，maxLen是最大长度，preSum是上一层的累加和，level是树深度
 */
int preOrder(BiTree* cur, int goal, int maxLen, int preSum, int level, map<int,int>& sum2level)
{
    if (cur == NULL)
        return maxLen;
    int curSum = preSum + cur->value;
    if (sum2level.find(curSum) == sum2level.end())//没找到新的累加和，直接创建新的pair存储
        sum2level[curSum] = level;
    if (sum2level.find(curSum - goal) != sum2level.end())//能找到curSum-goal说明该部分数的和满足goal，并且找到起始节点的上一层节点
        maxLen = std::max(maxLen, level - sum2level[curSum - goal]);//该节点所在层与起点父节点所在层做差就是路径长度
    maxLen = preOrder(cur->lchild, goal, maxLen, curSum, level + 1, sum2level);
    maxLen = preOrder(cur->rchild, goal, maxLen, curSum, level + 1, sum2level);

    //这一步很关键，每当遍历完叶节点之后，要把map的数据删除，以免影响其他枝叶上寻找最大长度时受到该叶节点的影响,最大长度会出现混乱
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
 * -3d3d10n0d1n6n9d2n1n
 */

