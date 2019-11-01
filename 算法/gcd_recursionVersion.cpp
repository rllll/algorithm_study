#include<iostream>
using namespace std;
int gcd(int m, int n)
{
    if (!n)
        return m;
    gcd(n, m%n);
}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << gcd(m,n) << endl;
    return 0;
}