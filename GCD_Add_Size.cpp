#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        unordered_map<long long, long long> f;
        long long mx = 0;
        for (long long i = 0; i < n; i++) // n
        {
            cin >> a[i];
            mx = max(mx, a[i]);
            f[a[i]]++; // 1
        }
        long long ans = n + 1;
        for (long long g = max(1LL, mx - n); g <= mx; g++) // 10^5
        {
            long long freq_of_multiples = 0;
            for (long long multiple = g; multiple <= mx; multiple += g) // log(g)(1e12)
                freq_of_multiples += f[multiple];

            if (freq_of_multiples > 0)
                ans = max(ans, freq_of_multiples + g);
        }
        cout << ans << '\n';
    }
    return 0;
}

// tc = O(n + 10^5 * log(g)1e12)
// sc = O(n) 