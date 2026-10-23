#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
long long fact[1000001];
long long invfact[1000001];

long long binpowmod(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void precompute()
{
    fact[0] = 1;
    for (long long i = 1; i <= 1000000; i++)
        fact[i] = ((fact[i - 1]) % MOD * (i % MOD)) % MOD;

    invfact[1000000] = binpowmod(fact[1000000], MOD - 2, MOD);
    for (long long i = 999999; i >= 0; i--)
        invfact[i] = ((invfact[i + 1] % MOD) * ((i + 1) % MOD)) % MOD;
}

int main()
{
    precompute();
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        long long top = fact[a] % MOD;
        long long bottom = ((invfact[b] % MOD) * (invfact[a - b] % MOD)) % MOD;
        long long result = ((top % MOD) * (bottom % MOD)) % MOD;
        cout << result << endl;
    }
    return 0;
}

// Time Complexity: O(10^6)
// Space Complexity: O(10^6)