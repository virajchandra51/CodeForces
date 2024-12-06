#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > dp;

int helper(int i, int j, string &a, string &b, string &c)
{
    if (i == a.size() && j == b.size())
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int pos = i + j; // pos in c
    int res = 1e9;

    if (i < a.size())
    {
        int cost = helper(i + 1, j, a, b, c) + (a[i] != c[pos]);
        res = min(res, cost);
    }
    if (j < b.size())
    {
        int cost = helper(i, j + 1, a, b, c) + (b[j] != c[pos]);
        res = min(res, cost);
    }

    return dp[i][j] = res;
}

// dp[i][j] = minimum cost to make c[0...i+j-1] from a[0...i-1] and b[0...j-1]

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b, c;
        cin >> a >> b >> c;
        int n = a.size();
        int m = b.size();
        dp.assign(n + 1, vector<int>(m + 1, -1));
        cout << helper(0, 0, a, b, c) << endl;
    }
    return 0;
}

// tc - O(n * m)
// sc - O(n * m)
