#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long sumOfNaturalNumbers(long long n)
{
    long long inv2 = 500000004; // inverse of 2 modulo MOD
    long long sum = ((n % MOD) * ((n + 1) % MOD)) % MOD;
    sum = (sum * inv2) % MOD;
    return sum;
}

int main()
{
    long long n;
    cin >> n;

    long long d = 1;
    long long answer = 0;

    while (d <= n)
    {
        long long n_by_d = n / d;

        long long start = d;
        long long end = n / n_by_d;

        long long block_sum = sumOfNaturalNumbers(end) - sumOfNaturalNumbers(start - 1);

        answer = ((answer % MOD) + ((block_sum % MOD) * (n_by_d % MOD)) % MOD) % MOD;

        d = end + 1;
    }

    cout << answer << endl;
    return 0;
}

// Time Complexity: O(sqrt(n))
// Space Complexity: O(1)