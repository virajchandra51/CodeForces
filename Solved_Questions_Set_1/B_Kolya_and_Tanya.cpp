#include <bits/stdc++.h>
using namespace std;

// long long moduloExponentiation(long long x, long long y, long long p)
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

// time complexity - O(log y) , where y is the power , returns (x^y)%p

int main()
{
    long long n;
    cin >> n; // taking input
    long long mod = 1e9 + 7;
    // long long allCases = 1;

    // modulo multplication
    // (a*b)%m = ((a%m)*(b%m))%m

    // for (int i = 1; i <= (3 * n); i++)
    // {
    //     allCases = ((allCases % mod) * (3 % mod)) % mod; // 3^(3*n) % mod
    // }

    // long long badCases = 1;
    // for (int i = 1; i <= (n); i++)
    // {
    //     badCases = ((badCases % mod) * (7 % mod)) % mod; // 7^n % mod
    // }

    long long allCases = moduloExponentiation(3, 3 * n, mod); // 3^(3*n) % mod
    long long badCases = moduloExponentiation(7, n, mod); // 7^n % mod

    // modulo substraction
    // (a-b)%m = ((a%m)-(b%m)+m)%m

    long long answer = (allCases % mod - badCases % mod + mod) % mod;
    cout << answer << endl;
    return 0;
}

// time complexity - O(3*n) almost equal to O(n)
// space complexity - O(1)