//
// 求两个有序链表的相同部分
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define maxsize 100

class Node
{
public:
    Node *next;
    int value;
public:
    Node():value(0),next(NULL){}
};

void getCommonPart(Node *head1, Node *head2)
{
    cout << "common part value:\n";
    while(head1 != NULL && head2 != NULL)
    {
        if (head1->value > head2->value)
            head2 = head2->next;
        else if (head1->value < head2->value)
            head1 = head1->next;
        else
        {
            cout << head1->value << endl;
            head1 = head1->next;
            head2 = head2->next;
        }
    }
}

int main()
{
    vector<Node> v1(maxsize);
    vector<Node> v2(maxsize);
    int arr1[10] = {2,5,6,8,7,4,9,12,45,16};
    sort(arr1, arr1+10);
    int arr2[8] = {4,21,64,3,7,26,5,9};
    sort(arr2, arr2+8);
    for (int i = 0; i < 10; ++i)
    {
        v1[i].value = arr1[i];
        v1[i].next = &v1[i+1];
    }
    for (int j = 0; j < 8; ++j)
    {
        v2[j].value = arr2[j];
        v2[j].next = &v2[j+1];
    }
    getCommonPart(&v1[0], &v2[0]);
    return 0;
}