#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
const long long EXPM = 1e9 + 6;

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
        long long a, b, c;
        cin >> a >> b >> c;
        long long exponent = binpowmod(b, c, EXPM);
        cout << binpowmod(a, exponent, MOD) << endl;
    }
    return 0;
}

// Time Complexity: O(log exponent)
// Space Complexity: O(1)