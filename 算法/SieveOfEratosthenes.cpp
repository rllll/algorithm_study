#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int v[n+1];
    //��ʼ������v[i] = i
    for (int i = 2; i <= n; i++)
        v[i] = i;
    for (int i = 2; i*i <= n; i++)
    {
        if (v[i] != 0)
        {
            int j = i*i;
            //��i*i��ʼ��������
            while(j <= n)
            {
                v[j] = 0;
                j = j+i;
            }
        }
    }
    for (int i = 2; i < n+1; i++)
    {
        if (v[i])
        {
            cout << v[i] << ' ';
        }
    }
    cout << endl;
    return 0;
}
