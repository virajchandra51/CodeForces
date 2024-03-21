#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> &vis, int par, int node, vector<vector<int> > &adj)
{
    vis[node] = 1;
    for (auto child : adj[node])
    {
        if (child == par)
            continue;
        if(vis[child] == 0)
        dfs(vis, node, child, adj);
    }
    return;
} // CC in graph

int main()
{
    int n;
    cin >> n;

    vector<vector<int> > adj(n + 26);
    for (int i = 0; i < n; i++) // n
    {
        string s;
        cin >> s;
        for (auto ch : s) // 50
        {
            adj[i].push_back(n + (ch - 'a'));
            adj[n + (ch - 'a')].push_back(i);
        }
    } //  n*50 ~ O(n) 

    vector<int> vis(n + 26, 0);
    int connectedComponents = 0;

    for (int i = n; i < n + 26; i++)
    {
        if (adj[i].size()>0 && vis[i]==0)
        {
            dfs(vis, -1, i, adj);
            connectedComponents++;
        }
    } // V+E - n+26+n*50 ~ O(n)
    cout << connectedComponents << endl;
    return 0;
}

// tc - O(n) ~ 10^5
// sc - O(n+26 + (n+26)*50)
