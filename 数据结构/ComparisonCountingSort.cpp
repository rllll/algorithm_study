#include<iostream>
using namespace std;

void ComparisonCountingSort(int *a, int size)
{
    int count[size]={0};
    for(int i = 0; i < size-1; i++)
    {
        for(int j = i+1; j < size; j++)
        {
            if(a[i] < a[j])
            {
                count[j]++;
            }
            else
            {
                count[i]++;
            }
        }
    }
    int Sort[size];
    for(int i = 0; i < size; i++)
    {
        Sort[count[i]] = a[i];
    }
    for(int i = 0; i < size; i++)
    {
        cout << Sort[i] << " ";
    }
}

void test()
{
    int a[10] = {4,12,78,23,56,23,67,19,45,17};
    int size = sizeof(a)/sizeof(int);
    ComparisonCountingSort(a,size);
}

int main()
{
    test();
    return 0;
}