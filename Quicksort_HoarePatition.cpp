#include <iostream>
using namespace std;
int HoarePartition(int *a, int l, int r)
{
    int p = a[l]; 
    int i = l, j = r;
    while (i < j)
    {
        while(a[j] >= p && i < j)
            j--;
        while(a[i] <= p && i < j)
            i++;
        swap(a[i],a[j]);
    }
    swap(a[l],a[i]);
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
    int a[num] = {42, 68, 35, 1, 70, 25, 79, 79, 35, 65};
    for (int i = 0; i < num; i++)
        cout << a[i] << " ";
    cout << endl;
    quicksort(a, 0, 9);
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}