#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long mod = 998244353;

        // taking input
        long long n;
        cin >> n;
        vector<long long> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        // finding max value
        long long maxValue = -1;
        for (int i = 0; i < n; i++)
            maxValue = max(maxValue, v[i]);

        long long countofLessThanMax = 0;
        long long countOfMax = 0;

        for (int i = 0; i < n; i++)
        {
            if (v[i] == maxValue - 1)
                countofLessThanMax++;
            if (v[i] == maxValue)
                countOfMax++;
        }

        long long totalPermutations = 1;
        long long badPermutations = 1;

        // modulo multiplication
        // (a*b)%mod = ((a%mod)*(b%mod))%mod

        for (long long i = 1; i <= n; i++)
        {
            totalPermutations = ((totalPermutations % mod) * (i % mod)) % mod;
            if (i != (countofLessThanMax + 1))
                badPermutations = ((badPermutations % mod) * (i % mod)) % mod;
        }

        long long nicePermutations;
        if (countOfMax > 1) // case 1
            nicePermutations = totalPermutations % mod;
        else // case 2
            nicePermutations = ((totalPermutations % mod) - (badPermutations % mod) + mod) % mod;

        cout << nicePermutations << endl;
    }
    return 0;
}

// time complexity O(n)
// space complexity O(1)