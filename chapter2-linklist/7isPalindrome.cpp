//
//判断一个链表是否为回文结构（要求时间复杂度O(N),空间复杂度O(1)）
//
#include <iostream>
#include <vector>
using namespace std;
#define maxsize 20

class Node
{
public:
    Node *next;
    int value;
    Node():value(NULL), next(NULL){}
};

bool isPalindrome(Node *head)
{
    if (head->next == NULL)
        cerr << "链表长度有问题，请重新输入！！" << endl;
    Node *slow = head;
    Node *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *mid = slow;
    Node *cur = mid->next;    Node *pre = NULL;    Node *next = NULL;
    while(cur != NULL)//逆序后半段链表
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    mid->next = pre;
    Node *lstart = head;    Node *rstart = mid->next;
    bool rst = true;
    while (rstart != NULL)//判断是否回文
    {
        if (lstart->value != rstart->value)
        {
            rst = false;
            break;
        }
        rstart = rstart->next;
        lstart = lstart->next;
    }
    cur = mid->next;    pre = NULL;    next = NULL;
    while(cur != NULL)//恢复链表
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    mid->next = pre;
    return rst;
}

int main()
{
    vector<Node> v1(maxsize);
    int arr1[6] = {1,2,3,4,2,1};
    for (int i = 0; i < 6; ++i)
    {
        v1[i].value = arr1[i];
        v1[i].next = i == 5 ? NULL : &v1[i+1];
    }
    vector<Node> v2(maxsize);
    int arr2[7] = {1,2,3,4,3,2,1};
    for (int i = 0; i < 7; ++i)
    {
        v2[i].value = arr2[i];
        v2[i].next = i == 6 ? NULL : &v2[i+1];
    }
    bool rst1 = isPalindrome(&v1[0]);
    cout << "arr1的结果是：";
    rst1 == 1 ? cout << "TRUE\n" : cout << "FALSE\n";
    bool rst2 = isPalindrome(&v2[0]);
    cout << "arr2的结果是：";
    rst2 == 1 ? cout << "TRUE\n" : cout << "FALSE\n";
    return 1;
}