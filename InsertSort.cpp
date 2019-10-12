#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int key = a[0];//限位器，防止j减小到-1
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while(a[j] != key && a[j] < a[j-1])
        {
            swap(a[j],a[j-1]);
            j--;
        }
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}