/*
�㷨��ѡ������
���������飺[3, 2, 6, 9, 4, 5, 2, 12]
���룺3 2 6 9 4 5 2 12
�����2 2 3 4 5 6 9 12
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
    cout << "��������Ԫ�ظ�����";
    cin >> n;
    int a[n];
    cout << "����Ԫ�أ�";
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
    cout << "��������";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}