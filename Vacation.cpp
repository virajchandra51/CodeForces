#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;

    vector<vector<long long> > a(n + 1, vector<long long>(m + 1, 0));
    vector<vector<long long> > prefixSum(n + 1, vector<long long>(m + 1, 0));

    for (long long i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            prefixSum[i][j] += (prefixSum[i][j - 1] + prefixSum[i - 1][j] - prefixSum[i - 1][j - 1]);
            if (a[i][j] == 0)
                prefixSum[i][j]++;
        }
    } // n*m

    long long q;
    cin >> q;
    for (int i = 0; i < q; i++) //q
    {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        long long countOfZeroes = prefixSum[x2][y2] - prefixSum[x1 - 1][y2] - prefixSum[x2][y1 - 1] + prefixSum[x1 - 1][y1 - 1];
        if (countOfZeroes > 0)
            cout << 0 << endl;
        else
            cout << 1 << endl;
    }

    return 0;
}

// tc - O(n*m + q) ~ 10^5
// sc - O(n*m)
