#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    vector<vector<long long> > adj(n + 1);
    vector<long long> deg(n + 1, 0);

    for (long long i = 0; i < n - 1; i++)
    {
        long long u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }

    vector<long long> val(n + 1);
    for (long long i = 1; i <= n; i++)
        val[i] = deg[i] - 2;

    long long res = LLONG_MIN;
    function<long long(long long, long long)> dfs = [&](long long u, long long parent) -> long long
    {
        long long mx1 = 0, mx2 = 0;

        for (long long v : adj[u])
        {
            if (v != parent) // no backtrack
            {
                long long temp = dfs(v, u);
                if (temp > mx1)
                {
                    mx2 = mx1;
                    mx1 = temp;
                }
                else if (temp > mx2)
                {
                    mx2 = temp;
                }
            }
        }
        res = max(res, mx1 + mx2 + val[u]);
        return max(mx1, mx2) + val[u];
    };

    dfs(1, -1);
    cout << res + 2 << endl;
}

// tc - O(n+m)
// sc - O(n+m)

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}