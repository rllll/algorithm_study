#include<iostream>
#include<vector>
using namespace std;

void HeapBottomUp(vector<int> &v)
{
    int i = v.size() / 2;
    while (i >= 1)
    {
        int k = i, t = v[k];
        bool heap = false;
        while(!heap && 2*k <= v.size()-1)
        {
            int j = 2*k;
            if (j < v.size()-1)
            {
                if (v[j] > v[j+1])
                    j = j+1;
            }
            if (t <= v[j])
            {
                heap = true;
            }
            else
            {
                v[k] = v[j];
                k = j;   
            }
            v[k] = t; 
        }
        i--;
    }
}
int main()
{
    vector<int> v={0, 42, 68, 35, 1, 70, 25, 79, 59, 35, 65};
    for (int i = 1; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    HeapBottomUp(v);
    while (v.size() != 1)
    {
        swap(v[1],v.back());
        cout << v.back() << " ";
        v.pop_back();
        int k = 1 , t = v[k];
        bool heap = false;
        while (!heap && 2*k <= v.size()-1)
        {
            int j = 2*k;
            if (j < v.size()-1)
            {
                if (v[j] > v[j+1])
                    j = j+1;
            }
            if (t <= v[j])
                heap = true;
            else
            {
                v[k] = v[j];
                k = j;
            }
            v[k] = t;
        }
        //HeapBottomUp(v);
    }
    return 0;
}