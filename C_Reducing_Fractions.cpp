#include <bits/stdc++.h>
using namespace std;

const int MAXV = 10000000;

int spf[MAXV + 1];
int topCnt[MAXV + 1], botCnt[MAXV + 1];

void buildSPF()
{
    for (long long i = 2; i <= MAXV; i++)
        if (spf[i] == i)
            for (long long j = i * i; j <= MAXV; j += i)
                if (spf[j] == j)
                    spf[j] = i;
}

// Time Complexity: O(10^7 log log 10^7)

int main()
{

    buildSPF();

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    // Count the number of copies of each prime in the top and bottom
    for (auto x : a)
    {
        while (x > 1)
        {
            int p = spf[x];
            while (x % p == 0)
            {
                x /= p;
                topCnt[p]++;
            }
        }
    }
    for (auto x : b)
    {
        while (x > 1)
        {
            int p = spf[x];
            while (x % p == 0)
            {
                x /= p;
                botCnt[p]++;
            }
        }
    }

    // Both sides lose min(top, bottom) copies of every prime
    for (int p = 2; p <= MAXV; p++)
        topCnt[p] = botCnt[p] = min(topCnt[p], botCnt[p]);

    // Reduce the top and bottom numbers by the number of copies of each prime that were lost
    for (int &x : a)
    {
        int y = x;
        while (y > 1)
        {
            int p = spf[y], how_many_p = 0;
            while (y % p == 0)
            {
                y /= p;
                how_many_p++;
            }

            int take = min(how_many_p, topCnt[p]);
            topCnt[p] -= take;
            while (take--)
                x /= p;
        }
    }

    for (int &x : b)
    {
        int y = x;
        while (y > 1)
        {
            int p = spf[y], how_many_p = 0;
            while (y % p == 0)
            {
                y /= p;
                how_many_p++;
            }

            int take = min(how_many_p, botCnt[p]);
            botCnt[p] -= take;
            while (take--)
                x /= p;
        }
    }

    // Output the reduced fractions

    cout << n << ' ' << m << '\n';
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << '\n';
    for (int i = 0; i < m; i++)
        cout << b[i] << ' ';
    cout << '\n';

    return 0;
}

// Time Complexity: O(n log a[i] + m log b[i] + 10^7 ln ln 10^7)
// Space Complexity: O(10^7)