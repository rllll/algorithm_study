#include<iostream>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    while(n)
    {
        int t = m%n;
        m = n;
        n = t;
    }
    cout << m << endl;
    return 0;
}