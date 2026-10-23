#include <bits/stdc++.h>
using namespace std;

long long candidate_calculation(long long p, long long &q, long long prime_factor)
{
    long long copies_in_p = 0, copies_in_q = 0;
    while (q % prime_factor == 0) // copies of prime_factor in q
    {
        copies_in_q++;
        q /= prime_factor;
    }
    long long temp = p;
    while (temp % prime_factor == 0) // copies of prime_factor in p
    {
        copies_in_p++;
        temp /= prime_factor;
    }

    // remove enough copies of prime_factor from p to make it not divisible by q
    long long copies_to_remove = copies_in_p - copies_in_q + 1;

    long long candidate = p;
    for (long long j = 0; j < copies_to_remove; j++)
        candidate /= prime_factor;

    return candidate;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long p, q;
        cin >> p >> q;
        if (p % q != 0)
        {
            cout << p << endl;
            continue;
        }

        long long ans = 1;
        for (long long i = 2; i * i <= q; i++)
        {
            if (q % i == 0)
            {
                ans = max(ans, candidate_calculation(p, q, i));
            }
        }

        if (q > 1)
            ans = max(ans, candidate_calculation(p, q, q));

        cout << ans << endl;
    }
    return 0;
}

// Time Complexity: O(sqrt(q) * log(p))
// Space Complexity: O(1)