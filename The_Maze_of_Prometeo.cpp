#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Iterative Function to calculate (x^y)%p
in O(log y) */
unsigned long long power(unsigned long long x,
                         int y, int p)
{
    unsigned long long res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
    // equal to p

    while (y > 0)
    {

        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n,
                              int p)
{
    return power(n, p - 2, p);
}

// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n,
                                 int r, int p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;

    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        long long spaces = k + 2;
        long long l_spaces = spaces / 2;
        long long r_spaces = k + 1 - l_spaces;
        long long items = n - 1;
        int m = 1e9 + 7;
        long long ans = ((nCrModPFermat(items - 1, l_spaces - 1, m) % m) * (nCrModPFermat(items - 1, r_spaces - 1, m) % m)) % m;
        ans = ((ans % m) * (2 % m)) % m;
        if (k == 0)
            ans = 2;
        cout << ans << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
