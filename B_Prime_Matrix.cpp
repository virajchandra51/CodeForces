#include <bits/stdc++.h>
using namespace std;

// Constants
vector<int> primes;
vector<bool> is_prime;

void Sieve(int n)
{
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++)
        if (is_prime[i])
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
    for (int i = 2; i <= n; i++)
        if (is_prime[i])
            primes.push_back(i);
}

// time complexity - O(n*log(log(n)))

int main()
{
    Sieve(100100);
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }
    // taking input

    int answer = INT_MAX;

    // first finding for rows
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < m; j++)
        {
            int moreRequired = (*lower_bound(primes.begin(), primes.end(), a[i][j]));
            // required value to become a prime
            count += moreRequired - a[i][j];
        }
        answer = min(answer, count);
    }

    // now for columns

    for (int i = 0; i < m; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            int moreRequired = (*lower_bound(primes.begin(), primes.end(), a[j][i]));
            // required value to become a prime
            count += moreRequired - a[j][i];
        }
        answer = min(answer, count);
    }

    cout << answer << endl;
    return 0;
}

// if count of primes upto 100100 is C

// time complexity - O( (n * m * log(C)) + complexity of sieve) ~ order of 10^5
// space complexity - O( max((n * m), size of sieve) )
