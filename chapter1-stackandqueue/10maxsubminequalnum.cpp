//
//最大值减去最小是小于或等于num的子数组数量
//
#include <iostream>
#include <deque>
#include <stdio.h>
using namespace std;

int getSubNumber(const int arr[], int len, int Num)
{
    if (Num <0)
    {
        cout << "请重新输入Num值！！" << endl;
        return 0;
    }
    deque<int> *qmax = new deque<int>();
    deque<int> *qmin = new deque<int>();
    int rst = 0;
    int left = 0;
    int right = 0;
    for (int i = 0; i < len; ++i)
    {
        right = i;
        while (!qmax->empty() && arr[qmax->back()] <= arr[i])
        {
            qmax->pop_back();
        }
        qmax->push_back(i);
        while (!qmin->empty() && arr[qmin->back()] >= arr[i])
        {
            qmin->pop_back();
        }
        qmin->push_back(i);
        if (right - left >= 1)
        {
            while (arr[qmax->front()] - arr[qmin->front()] > Num)
            {
                rst = rst + right -1 - left;
                while (qmax->front() <= left)
                    qmax->pop_front();
                while (qmin->front() <= left)
                    qmin->pop_front();
                left++;
            }
            if (right == len -1)
            {
                while (right - left >= 1)
                {
                    rst = rst + len -1 - left;
                    left++;
                }
            }

        }
    }
    qmax = NULL;
    delete qmax;
    qmin = NULL;
    delete qmin;
    return rst;
}

int main()
{
    int arr[10] = {1,1,4,6,8,9,6,2,7,5};
    int Num = 0;
    int len = sizeof(arr) / sizeof(arr[0]);
    int number = getSubNumber(arr, len, Num);
    cout << "符合要求的子数组数量：";
    cout << number << endl;
    return 0;
}
