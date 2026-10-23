#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000000;
int spf[MAXN];

void buildSPF()
{
    for (long long i = 2; i <= MAXN; i++)
        if (spf[i] == 0)
        {
            spf[i] = i;
            for (long long j = i * i; j <= MAXN; j += i)
                if (spf[j] == 0)
                    spf[j] = i;
        }
} // O(n ln ln n)

unordered_set<int> getPrimes(int v)
{
    unordered_set<int> primes;
    string s = to_string(v);
    sort(s.begin(), s.end());

    do
    {
        if (s[0] == '0')
            continue; // no leading zeros
        int x = stoi(s);
        while (x > 1)
        { // factorize with spf
            int p = spf[x];
            primes.insert(p);
            while (x % p == 0)
                x /= p;
        }
    } while (next_permutation(s.begin(), s.end()));

    return primes;
} // O(d! log 10^7 + d log d), where d is the number of digits in v

int main()
{
    buildSPF();
    int t;
    cin >> t;
    while (t--)
    {
        int X, Y;
        cin >> X >> Y;
        unordered_set<int> A = getPrimes(X), B = getPrimes(Y);

        int ans = 1;
        for (int p : A)
            if (B.count(p))
                ans = max(ans, p);
        cout << ans << '\n';
    }
}

// Time Complexity: O(10^7 ln ln 10^7 + t * (d! log 10^7 + d log d))
// Space Complexity: O(10^7)