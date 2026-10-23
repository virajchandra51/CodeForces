#include <bits/stdc++.h>
using namespace std;

const int MAXV = 1e6 + 1;

int main()
{
    long long n;
    cin >> n;
    vector<long long> count(MAXV);
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        count[x]++;
    }

    vector<long long> divisible_by_d(MAXV);
    vector<long long> pairs_with_gcd_d(MAXV);

    for (long long d = 1; d < MAXV; d++)
    {
        for (long long m = d; m < MAXV; m += d)
            divisible_by_d[d] += count[m];
    }

    for (long long d = MAXV - 1; d >= 1; d--)
    {
        long long pairs_divisible_by_d = (divisible_by_d[d]) * (divisible_by_d[d] - 1) / 2;

        for (long long m = 2 * d; m < MAXV; m += d)
            pairs_divisible_by_d -= pairs_with_gcd_d[m];

        pairs_with_gcd_d[d] = pairs_divisible_by_d;
    }

    cout << pairs_with_gcd_d[1] << endl;

    return 0;
}

// Time Complexity: O(10^6 * log(10^6))
// Space Complexity: O(10^6)