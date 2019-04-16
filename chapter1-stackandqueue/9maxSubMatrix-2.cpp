//
//求矩阵的最大子矩阵和并找出该矩阵
//原矩阵的元素可正可负
//有问题
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <random>
using namespace std;

#define random(x) (random()%(2*x)-x) //求（-x,x）之间的随机整数

int* getSubMaxinLine(const int line[], int length)
{
    int rowlocationres[3];//依次存储最大子矩阵左边界，右边界，和
    int *p = rowlocationres;
    int sum = 0;
    int maxsum = 0;
    p[0] = 0;
    p[1] = length - 1;
    int tmp = 0;
    for (int i = 0; i < length; ++i)
    {
        tmp = p[0];
        if (sum >= 0)
        {
            sum = sum + line[i];
        }
        else
        {
            sum = line[i];
            p[0] = i;
        }
        if (sum >= maxsum)
        {
            maxsum = sum;
            p[1] = i;
        }
        else
            p[0] = tmp;
    }
    p[2] = maxsum;
    return p;
}

void getSubMaxinMatrix(const int Matrix[5][8], int row, int column)
{
    int matrixlocationres[5];//依次存入左边界、右边界、上边界、下边界、最大和
    int *p = matrixlocationres;
    int *p1;
    int maxsize = 0;
    p[2] = 0;
    p[3] = row -1;
    for (int i = 0; i < row; ++i)
    {
        int rowsum[column]={0};
        for (int j = i; j < row; ++j)
        {
            for (int k = 0; k < column; ++k)
            {
                rowsum[k] += Matrix[j][k];
            }
            p1 = getSubMaxinLine(rowsum, column);
            if (p1[2] >= maxsize)
            {
                maxsize = p1[2];
                p[0] = p1[0];
                p[1] = p1[1];
                p[2] = i;
                p[3] = j;
                p[4] = maxsize;
            }
        }
    }
    cout << "最大子矩阵四角位置：（起始位置为1）" << endl;
    cout << "左上角" << "(" << p[2]+1 << "," << p[0]+1 <<")" << endl;
    cout << "右上角" << "(" << p[2]+1 << "," << p[1]+1 <<")" << endl;
    cout << "左下角" << "(" << p[3]+1 << "," << p[0]+1 <<")" << endl;
    cout << "右下角" << "(" << p[3]+1 << "," << p[1]+1 <<")" << endl;
    cout << "最大子矩阵：" << endl;
    for (int k = p[2]; k < (p[3]+1); ++k)
    {
        for (int j = p[0]; j < (p[1]+1); ++j)
        {
            cout.width(4);
            cout << Matrix[k][j] ;
        }
        cout << endl;
    }
    cout << "最大子矩阵和是：" << p[4] << endl;
    return;
}

int main()
{
    srand((unsigned int) time(0));
    int Matrix[5][8];
    int M = sizeof(Matrix)/ sizeof(*Matrix);//row *Matrix是Matrix[0]
    int N = sizeof(*Matrix)/ sizeof((*Matrix)[0]);//col (*Matrix)[0]是Matrix[0][0]
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            Matrix[i][j] = random(20);
            cout.width(4);
            cout << Matrix[i][j] ;
        }
        cout << endl;
    }
    getSubMaxinMatrix(Matrix, M, N);
    return 0;
}