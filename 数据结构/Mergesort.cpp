#include<iostream>
#include<vector>
using namespace std;

void Merg(vector<int> b, vector<int> c, vector<int> &a)
{
    int i = 0, j = 0;
    int k = 0;
    while(i < b.size() && j < c.size())
    {
        if (b[i] < c[j])
        {
            a[k] = b[i];
            i++;
        }
        else
        {
            a[k] = c[j];
            j++;
        }
        k++;
    }
    if (i < b.size())
    {
        while (i < b.size())
        {
            a[k] = b[i];
            i++;
            k++;
        }
    }
    if (j < c.size())
    {
        while (j < c.size())
        {
            a[k] = c[j];
            j++;
            k++;
        }
    }
}

void Mergesort(vector<int> &a)
{
    if (a.size() > 1)
    {
        vector<int> b,c;
        for (int i = 0; i < a.size(); i++)
        {
            if (i < a.size()/2)
                b.push_back(a[i]);
            else
                c.push_back(a[i]);            
        }
        Mergesort(b);
        Mergesort(c);
        Merg(b,c,a);
    }
}
int main()
{
    vector<int> v={42, 68, 35, 1, 70, 25, 79, 59, 35, 65};
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    Mergesort(v);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}