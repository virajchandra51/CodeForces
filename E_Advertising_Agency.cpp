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

        long long smallestBlogger = v[k-1]; 
        // since the smallest blogger's follower count 
        // is kept at the (k-1)th index of the dec sorted array

        long long y = 0; // y = count of smallest element that you are going to take in your selected bloggers
        long long x = 0; // x = total count of those bloggers available with that smallest value

        for (int i = 0; i < n; i++)
        {
            if(v[i]==smallestBlogger) x++;
        }

        for (int i = 0; i < k; i++)
        {
            if(v[i]==smallestBlogger) y++;
        }

        long long answer = nCrMod(x, y, mod);  // xCy % mod
        cout << answer << endl;
    }
    return 0;
}

// time complexity O(n)
// space complexity O(1)