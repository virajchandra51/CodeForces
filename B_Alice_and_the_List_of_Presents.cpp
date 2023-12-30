#include <bits/stdc++.h>
using namespace std;

long long power(long long x, long long y, long long p)
{
    long long res = 1; // Initialize result
    x = x % p;         // Update x if it is more than or // equal to p
    if (x == 0)
        return 0; // In case x is divisible by p;
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

int main()
{
    long long n, m;
    cin >> n >> m; // taking input
    long long mod = 1e9+7;
    long long answer = power(power(2, m, mod) - 1, n, mod); // (2^m-1)^n 
    cout << answer << endl;
    return 0;
}

// time complexity - O(log y)
// space complexity - O(1)