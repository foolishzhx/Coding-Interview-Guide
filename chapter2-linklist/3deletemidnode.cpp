//
//删除链表的中间节点和a/b处节点
//
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
#define maxsize 20

class Node
{
public:
    int value;
    Node *next;
public:
    Node():value(NULL), next(NULL){}
};

Node *deletemidNode(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    else if (head->next->next == NULL)
        return head->next;
    Node *slow = head;
    Node *fast = head;
    Node *pre = NULL;
    while (fast->next && fast->next->next)
    {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    pre->next = slow->next;
    return head;
}

Node *deleteAdivideBnode(Node *head, int a, int b)
{
    if (a > b || a < 1)
    {
        cout << "math error,请重新输入a和b！！";
        return head;
    }
    Node *cur = head;
    int n = 1;
    while (cur->next)
    {
        n++;
        cur = cur->next;
    }
    n =(int) ceil(((double) (a * n)) / (double) b);
    if (n == 1)
    {
        head = head->next;
    }
    else if (n > 1)
    {
        cur = head;
        for (int i = 0; i < n - 2; ++i) {
            cur = cur->next;
        }
        cur->next = cur->next->next;
    }
    return head;
}

int main()
{
    vector<Node> v1(maxsize);
    int arr1[10] = {2,5,6,8,7,4,9,12,45,16};
    for (int i = 0; i < 10; ++i)
    {
        v1[i].value = arr1[i];
        v1[i].next = &v1[i+1];
        if (i == 9)
            v1[i].next = NULL;
    }
    vector<Node> v2(maxsize);
    int arr2[8] = {4,21,64,3,7,26,5,9};
    for (int j = 0; j < 8; ++j)
    {
        v2[j].value = arr2[j];
        v2[j].next = &v2[j+1];
        if (j == 7)
            v2[j].next = NULL;
    }
    Node *head1 = deletemidNode(&v1[0]);
    Node *head2 = deleteAdivideBnode(&v2[0], 5, 9);
    return 0;
}
