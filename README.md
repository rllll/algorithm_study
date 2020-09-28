# algorithm_study

学习数据结构与算法的记录

**预留了两个配置文件，分别属于VS和VScode（11.1整理了杂乱文件）**

持续更新中...（2019年10月12日始）

排序算法集中版：

```c++
#include<iostream>
#include<unordered_map>
#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<string.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
using namespace std;

typedef long long ll;

class order
{
private:
    vector<int> nums;
    int size;
public:
    void init();
    void display(const vector<int>& o_nums);
    void selects_sort();
    void bubble_sort();
    void insert_sort();
    void merge(const vector<int>& v1,const vector<int>& v2, vector<int>& m_tmp);
    void merge_sort_helper(vector<int>& tmp);
    void merge_sort();

    int select_k(vector<int>& tmp, int left, int right);
    void quick_sort_helper(vector<int>& tmp, int left, int right);
    void quick_sort();
};

void order::init()
{
    cout << "input your number's size: ";
    cin >> size;
    cout << "input your numbers: ";
    for (int i = 0; i < size; ++i)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
}

void order::display(const vector<int>& o_nums)
{
    cout << "your current numbers: ";
    for (int i = 0; i < o_nums.size(); ++i)
        cout << o_nums[i] << " ";
    cout << endl;
}

void order::selects_sort()
{
    cout << "========select_sort========" << endl;
    vector<int> tmp(nums);
    for (int i = 0; i < size-1; ++i)
    {
        int minval = tmp[i];
        int min_i = i;
        for (int j = i+1; j < size; ++j)
        {
            if (minval > tmp[j]) minval = tmp[j], min_i = j;
        }
        swap(tmp[i],tmp[min_i]);
    }
    display(tmp);
}

void order::bubble_sort()
{
    cout << "========bubble_sort========" << endl;
    vector<int> tmp(nums);
    for (int i = 0; i < size-1; ++i)
    {
        int flag = 0;
        for (int j = 0; j < size-1-i; ++j)
        {
            if (tmp[j] > tmp[j+1])
            {
                swap(tmp[j],tmp[j+1]);
                flag = 1;
            }
        }
        if (!flag)
            break;
    }
    display(tmp);
}

void order::insert_sort()
{
    cout << "========insert_sort========" << endl;
    vector<int> tmp(nums);
    for (int i = 1; i < size; ++i)
    {
        for (int j = i; j >= 1; --j)
        {
            if (tmp[j] < tmp[j-1]) swap(tmp[j],tmp[j-1]);
        }
    }
    display(tmp);
}

void order::merge(const vector<int>& v1,const vector<int>& v2, vector<int>& m_tmp)
{
    int i = 0, j = 0;
    int k = 0;
    while(i < v1.size() && j < v2.size())
    {
        if (v1[i] < v2[j])
            m_tmp[k++] = v1[i++];
        else
            m_tmp[k++] = v2[j++];
    }
    while(i < v1.size())
        m_tmp[k++] = v1[i++];
    while(j < v2.size())
        m_tmp[k++] = v2[j++];
}

void order::merge_sort_helper(vector<int>& tmp)
{
    if (tmp.size() > 1)
    {
        vector<int> v1,v2;
        for(int i = 0; i < tmp.size(); ++i)
        {
            if (i < tmp.size()/2)
                v1.push_back(tmp[i]);
            else
                v2.push_back(tmp[i]);
        }
        merge_sort_helper(v1);
        merge_sort_helper(v2);
        merge(v1,v2,tmp);
    }
}

void order::merge_sort()
{
    cout << "========merge_sort========" << endl;
    vector<int> tmp(nums);
    merge_sort_helper(tmp);
    display(tmp);
}

int order::select_k(vector<int>& tmp, int left, int right)
{
    int cmp_num = tmp[right];
    int j = left-1;
    for (int i = left; i < right; ++i)
    {
        if (tmp[i] < cmp_num)
        {
            ++j;
            if (j != i)
                swap(tmp[i],tmp[j]);
        }
    }
    ++j;
    swap(tmp[j],tmp[right]);
    return j;
}

void order::quick_sort_helper(vector<int>& tmp, int left, int right)
{
    if (left < right)
    {
        int select_pos = select_k(tmp,left,right);
        quick_sort_helper(tmp,left,select_pos-1);
        quick_sort_helper(tmp,select_pos+1,right);
    }
}

void order::quick_sort()
{
    cout << "========quick_sort========" << endl;
    vector<int> tmp(nums);
    quick_sort_helper(tmp,0,size-1);
    display(tmp);
}

int main()
{
    /*
    10
    3 2 6 9 4 5 2 12 8 66
    */
    order o;
    o.init();
    o.selects_sort();
    o.bubble_sort();
    o.insert_sort();
    o.merge_sort();
    o.quick_sort();
    return 0;
}
```
