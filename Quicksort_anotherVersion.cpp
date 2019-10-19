#include <iostream>
using namespace std;

int HoarePartition(int *a, int l, int r)
{
    int p = a[l];
    int i = l, j = r;
    while (i < j)
    {
        while(i < j && a[j] > p)
            j--;
        if (i < j)
            a[i++] = a[j];
        while(i < j && a[i] < p)
            i++;
        if (i < j)
            a[j--] = a[i];
        
    }
    a[i] = p;
    return i;
}

void quicksort(int *a, int l, int r)
{
    if (l < r)
    {
        int s = HoarePartition(a, l, r);
        quicksort(a, l, s - 1);
        quicksort(a, s + 1, r);
    }
}

int main()
{
    int num = 10;
    int a[num];
    for (int i = 0; i < num; i++)
    {
        a[i] = 1 + rand() % 100;
        cout << a[i] << " ";
    }
    cout << endl;
    quicksort(a, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}