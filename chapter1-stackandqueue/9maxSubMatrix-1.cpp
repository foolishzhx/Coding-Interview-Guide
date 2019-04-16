//
//最大子矩阵的大小(矩阵中全为0,1，求最大全1的矩形面积) 时间复杂度O（M*N）
//提供两种思路：
//1转成直方图，求直方图中最大快面积
//2先求每行最大子块，再求从该行向下累计多行的最大子快，最后遍历每行
//3遍历全部的元素，求每个元素的位置能向左延伸最大长度L，向右延伸最大长度R，向上延伸最大长度H，时间复杂度O(M*2N)
//

#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

int getMaxMatrix(int Matrix[6][7], int row, int column)
{
    int H[column]={0};//存放直方图的高度
    int i, j;
    int maxsize = 0;
    stack<int> st;
    for (i = 0; i < row; i++)
    {
        int cur = 0;
        for (j = 0; j<column; j++)
        {
            H[j] = Matrix[i][j] == 0 ? 0 : H[j]+1;
            while(!st.empty() && H[j] <= H[st.top()])
            {
                cur = st.top();
                st.pop();
                if(st.empty())
                    maxsize = max(H[cur] * (j), maxsize);
                else
                    maxsize = max(H[cur] * (j-st.top()-1), maxsize);

            }
            st.push(j);
        }
        while(!st.empty())
        {
            cur = st.top();
            st.pop();
            if(st.empty())
                maxsize = max(H[cur] * (column), maxsize);
            else
                maxsize = max(H[cur] * (column-st.top()-1), maxsize);
        }
    }
    return maxsize;
}

int main()
{

    int Matrix[6][7] = {{1,1,0,1,1,1,0},
                        {1,0,1,0,0,1,1},
                        {0,1,1,1,0,1,0},
                        {1,1,1,0,1,1,1},
                        {1,1,1,1,1,1,1},
                        {1,1,1,1,0,1,1}
                        };
    int M = sizeof(Matrix)/ sizeof(*Matrix);//row *Matrix是Matrix[0]
    int N = sizeof(*Matrix)/ sizeof((*Matrix)[0]);//col (*Matrix)[0]是Matrix[0][0]
    int maxsize = getMaxMatrix(Matrix, M, N);
    cout << "最大子矩阵面积是：" << maxsize << endl;
    return 0;
}