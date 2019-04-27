//
//生成窗口最大数值
//
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> getMaxWindow(vector<int> &arr, int w)
{
    deque<int> *qmax = new deque<int>;//双向队列
    size_t len = arr.size();
    vector<int> rst;
    rst.reserve(len - w + 1);
    if(len == 0 || len < w || w <1) {
        cerr << "数据有问题！！";
        return rst;
    }
    for (int i = 0; i < len ; i++)
    {
        while(!qmax->empty() && arr[qmax->back()] <= arr[i])
            qmax->pop_back();
        qmax->push_back(i);
        if(qmax->front() == i-w)
            qmax->pop_front();
        if(i >= w-1)
            rst.push_back(arr[qmax->front()]);
    }
    return rst;
}

int main(int argc, char** argv)
{
    vector<int> arr = {1,2,3,4,5,6,7,6,2,3,4,1,5,6,3,8};
    vector<int> rst = getMaxWindow(arr, atoi(argv[1]));
    for(auto iter = rst.begin(); iter != rst.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
    return 0;
}
