#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

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

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        cout << binpowmod(a, b, MOD) << endl;
    }
    return 0;
}

// Time Complexity: O(log b)
// Space Complexity: O(1)