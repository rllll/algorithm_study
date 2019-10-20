#include<iostream>
#include<vector>
using namespace std;

int reverse(int number)
{
    vector<int> store;
    while (number)
    {
        store.push_back(number%10);
        number /= 10;
    }
    int new_number = 0;
    for (int i = 0; i < store.size(); i++)
    {
        new_number  = new_number*10 + store[i];
    }
    return new_number;
}

bool isprime(int number)
{
    for (int i = 2; i * i <= number; i++)
    {
        if (number%i == 0)
        {
            return false;
        }
    }
    return true;
}

int getminprime(int number)
{
    for (int i = 2; i <= number; i++)
    {
        if (number % i == 0 && isprime(i))
        {
            return i;
        }
    }
    return 1;
}

int getstep(int number)
{
    if (number < 10)
    {
        return 0;
    }
    else
    {
        int count = 0;
        while(true)
        {
            int old_number = number;
            int min_prime = getminprime(number);
            if (min_prime == number)
            {
                number = reverse(number);
            }
            else
            {
                number = number / min_prime;
                number = reverse(number); 
            }
            if (isprime(number) && isprime(old_number) && (number < 10 || number >= old_number))
            {
                break;
            }
            else
            {
                count++;
            }
        }
        return count;
    }
}

int main()
{
    int m,n;
    cin >> m >> n;
    int maxstep = 0;
    for (int i = m; i <= n; i++)
    {
        int stepnum = getstep(i);
        if (maxstep < stepnum)
            maxstep = stepnum;
    }
    cout << maxstep << endl;
    // cin >> m;
    // cout << getstep(m) << endl;
    return 0;
}