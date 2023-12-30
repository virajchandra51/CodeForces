#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m; // taking dimensions
    long long a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    long long answer = 0;
    // don't use pow function for calculating powers of 2.
    for (int i = 0; i < n; i++)
    {
        long long c = 0;
        for (int j = 0; j < m; j++)
        {
            c += a[i][j]; // number of 1s 
        }
        answer += ((1LL<<(c)) - 1); // 2^c
        answer += ((1LL<<(m - c)) - 1);
    }
    for (int i = 0; i < m; i++)
    {
        long long c = 0;
        for (int j = 0; j < n; j++)
        {
            c += a[j][i];
        }
        answer += ((1LL<<(c)) - 1);
        answer += ((1LL<<(n - c)) - 1);
    }
    cout << answer - n * m << endl;
    return 0;
}