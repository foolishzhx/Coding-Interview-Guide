//
//生成窗口最大数值
//
#include <iostream>
#include <stdio.h>
#include <deque>

using namespace std;

int *getMaxWindow(int arr[], int len, int w)
{
    deque<int>* qmax = new deque<int>();//双向队列
    int *rst = new int[len - w + 1];
    int index = 0;
    if(len == 0 || len < w || w <1)
        return 0;
    for (int i = 0; i < len ; i++) {
        while(!qmax->empty() && arr[qmax->back()] <= arr[i])
        {
            qmax->pop_back();
        }
        qmax->push_back(i);
        if(qmax->front() == i-w)
            qmax->pop_front();
        if(i>=w-1)
            rst[index++] = arr[qmax->front()];
    }
    qmax = NULL;
    delete qmax;
    return rst;
}

int main()
{
    int arr[] = { 4, 3, 5, 4, 3, 3, 6, 7 };
    int w = 3;
    int len = sizeof(arr)/ sizeof(int);
    int len2 = len - w + 1;
    int* p = getMaxWindow(arr, len, w);
    for (int i = 0; i < len2; i++)
    {
        cout << p[i] << endl;
    }
    p = NULL;
    delete p;
    return 0;
}
