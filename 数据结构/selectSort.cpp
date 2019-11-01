/*
算法：选择排序
待排序数组：[3, 2, 6, 9, 4, 5, 2, 12]
输入：3 2 6 9 4 5 2 12
输出：2 2 3 4 5 6 9 12
*/
#include<iostream>
using namespace std;

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n;
    cout << "输入数组元素个数：";
    cin >> n;
    int a[n];
    cout << "数组元素：";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n-1; i++)
    {
        int minpos = i;
        for (int j = i+1; j < n; j++)
        {
            if (a[minpos] > a[j])
            {
                minpos = j;
            }
        }
        Swap(&a[i],&a[minpos]);
    }
    cout << "排序结果：";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}