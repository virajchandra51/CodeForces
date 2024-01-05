#include <bits/stdc++.h>
using namespace std;

long long power(long long x, int y, int p)
{
    long long res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

long long modInverse(long long n, int p)
{
    return power(n, p - 2, p);
}

long long nCrMod(long long n, int r, int p)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

// Returns nCr % p in time complexity O(n)

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long mod = 1e9 + 7;
        long long n, k;
        cin >> n >> k;
        vector<long long> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        // taking input

        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());

        // setting array in dec order

        map<long long, long long> freq;
        map<long long, long long> takenBloggers;

        for (int i = 0; i < n; i++)
            freq[v[i]]++;
        for (int i = 0; i < k; i++)
            takenBloggers[v[i]]++;

        long long ans = 1;

        // modulo multiplcation technique

        for (auto it : takenBloggers)
        {
            // it.first = key = follower count
            // it.second = value = number of wanted bloggers having this follower count
            long long differentWays = nCrMod(freq[it.first], it.second, mod);
            ans = ((ans) % mod * (differentWays) % mod) % mod;
        }

        cout << ans << endl;
    }
    return 0;
}

// let's say k = 1000, n = 1000
// case1 - all numbers are different - outer loop runs N times, nCrMod runs in O(1)
// case2 - all numbers are same - outer loop runs 1 time, nCrMod runs in O(n)

// time complexity O(n)
// space complexity O(n)