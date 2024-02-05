#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int> > &adj, vector<int> &vis, int initialNode, int &flag)
{
    vis[node] = 1;
    for (auto child : adj[node])
    {
        if (vis[child] == 0)
        {
            dfs(child, adj, vis, initialNode, flag);
        }
        else if(vis[child] == 1)
        {
            flag = 1;
        }
    }
    if(flag)
    if (flag == 0)
        vis[node] = 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int> > adj(n, vector<int>());
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            int b = (a + 1 + i) % n;
            adj[i].push_back(b);
        }

        vector<int> vis(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 0)
            {
                int flag = 0;
                dfs(i, adj, vis, i, flag);
            }
        }
        for(auto it:vis) ans+=it;
        cout <<ans<< endl;
    }
    return 0;
}

// TC - O(n)
// SC - O(n)