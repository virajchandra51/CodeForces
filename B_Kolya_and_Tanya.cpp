#include <bits/stdc++.h>
using namespace std;

// long long power(long long x, long long y, long long p)
// {
//     long long res = 1; // Initialize result
//     x = x % p;         // Update x if it is more than or // equal to p
//     if (x == 0)
//         return 0; // In case x is divisible by p;
//     while (y > 0)
//     {
//         // If y is odd, multiply x with result
//         if (y & 1)
//             res = (res * x) % p;
//         // y must be even now
//         y = y >> 1; // y = y/2
//         x = (x * x) % p;
//     }
//     return res;
// }

int main()
{
    long long n;
    cin >> n; // taking input
    long long mod = 1e9 + 7;
    // long long answer = (power(3, 3 * n, mod) - power(7, n, mod) + mod ) % mod;
    long long answer = 1;
    // modulo multplication
    // (a*b)%m = ((a%m)*(b%m))%m
    // modulo substraction
    // (a-b)%m = ((a%m)-(b%m)+m)%m
    for (int i = 1; i <= (3 * n); i++)
    {
        answer = ((answer % mod) * (3 % mod)) % mod;
    }
    long long answer2 = 1;
    for (int i = 1; i <= (n); i++)
    {
        answer2 = ((answer2 % mod) * (7 % mod)) % mod;
    }
    cout << (answer % mod - answer2 % mod + mod) % mod << endl;
    return 0;
}

// time complexity - O(3*n)
// space complexity - O(1)