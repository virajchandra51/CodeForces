#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vector<int> dp(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    function<int(int)> dfs = [&](int node) -> int
    {
        if (dp[node] != -1)
        {
            return dp[node];
        }
        int ans = 0;
        for (int child : adj[node])
        {
            ans = max(ans, 1 + dfs(child));
        }
        return dp[node] = ans;
    };
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == -1)
        {
            dp[i] = dfs(i);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}