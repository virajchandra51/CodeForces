#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int> > &adj, vector<int> &vis, unordered_set<int> &ans)
{
    vis[node] = 1; // this node was just encountered and i have marked it visited

    int child = adj[node][0];

    if (vis[child] == 2)
    {
        // do nothing
    }
    else if (vis[child] == 1)
    {
        int curNode = child;
        do
        {
            ans.insert(curNode);
            curNode = adj[curNode][0];
        } while (curNode != child);
    }
    else
    {
        dfs(child, adj, vis, ans);
    }
    
    vis[node] = 2; // if i have explored the component totally then i need to backtrack 
    // i will mark that node as value 2, because this will now denote that this cyclic compnent ahas been
    // fully traversed
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
        unordered_set<int> ans; // O(1)

        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 0)
                dfs(i, adj, vis, ans);
        } // V+E - O(N)

        cout << ans.size() << endl;
    }
    return 0;
}

// tc - O(n) ~ 10^6
// sc - O(n*1 + n) - O(n)