#include <iostream>
#include <vector>
using namespace std;

vector<bool> sieve(int n)
{
    vector<bool> primes(n + 1, true);

    for (int i = 2; i * i <= n; i++)
    {

        if (primes[i])
        {
            for (int p = i * i; p <= n; p += i)
            {
                primes[p] = false;
            }
        }
    }
    return primes;
}

int main()
{

    int n = 100;
    vector<bool> primes = sieve(n);

    for (int i = 2; i <= n; i++)
    {
        if (primes[i] == true)
        {
            cout << i << " ";
        }
    }

    return 0;
}