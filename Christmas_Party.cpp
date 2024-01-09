#include <bits/stdc++.h>
using namespace std;

long long modInverse(long long A, long long M)
{
    long long m0 = M;
    long long y = 0, x = 1;
    if (M == 1)
        return 0;
    while (A > 1)
    {
        long long q = A / M;
        long long t = M;
        M = A % M, A = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;

    return x;
}

// time complexity O(log M)

int main()
{
    long long mod = 1e9 + 7;

    long long n;
    cin >> n; // taking input

    if (n == 1) // base case
    {
        cout << 0 << endl;
        return 0;
    }

    vector<long long> fact(n + 1, 0);
    fact[0] = 1;
    fact[1] = 1;
    fact[2] = 2;

    for (long long i = 3; i <= n; i++)
    {
        fact[i] = ((fact[i - 1]) % mod * (i % mod)) % mod;
    }

    // calculating factorials values upto n

    long long answer = 0; // total ways
    long long sign = 1;   // maintaing variable to accomodate sign change

    // formula looks like, Answer = n! * ( 1/2! - 1/3! + 1/4! .... ((-1)^n * 1/n!) )

    for (int i = 2; i <= n; i++)
    {
        long long modInverseValue = modInverse(fact[i], mod);
        long long s = ((fact[n] % mod) * (modInverseValue % mod)) % mod; //modulo multiplication
        if (sign == 1)
        {
            answer = ((answer % mod) + (s % mod)) % mod;
        }
        else
        {
            answer = ((answer % mod) - (s % mod) + mod) % mod;
        }
        sign *= -1;
    }

    cout << answer << endl;

    return 0;
}

// time complexity - O(n*log(mod))
// space complexity - O(n)