#include <bits/stdc++.h>
using namespace std;

long long next_prime(long long n)
{
    for (long long i = n;; i++) // log2(10^4) = O(10)
    {
        bool isPrime = true;
        for (long long j = 2; j * j <= i; j++) // O(10^2)
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
        {
            return i;
        }
    }
} // O(1000)

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long d;
        cin >> d;

        long long p = next_prime(d + 1); // O(1000)
        long long q = next_prime(p + d); // O(1000)

        long long a = min(1LL * p * p * p, 1LL * p * q);
        cout << a << endl;
    }
}

// tc = O(10^3)
// sc = O(1)