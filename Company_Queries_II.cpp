#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 200005;
const int LOG = 17; // log2(MAXN) ~ 17

vector<int> adj[MAXN];
int up[MAXN][LOG]; // up[v][j] is the 2^j-th ancestor of v
int depth[MAXN];

void dfs(int v, int p)
{
    up[v][0] = p;
    for (int i = 1; i < LOG; i++)
    {
        if (up[v][i - 1] != -1)
        {
            up[v][i] = up[up[v][i - 1]][i - 1];
        }
        else
        {
            up[v][i] = -1;
        }
    }
    for (int u : adj[v])
    {
        if (u != p)
        {
            depth[u] = depth[v] + 1;
            dfs(u, v);
        }
    }
}

int lca(int u, int v)
{
    if (depth[u] < depth[v])
    {
        swap(u, v);
    }
    int diff = depth[u] - depth[v];
    for (int i = 0; i < LOG; i++)
    {
        if ((diff >> i) & 1)
        {
            u = up[u][i];
        }
    }
    if (u == v)
    {
        return u;
    }
    for (int i = LOG - 1; i >= 0; i--)
    {
        if (up[u][i] != up[v][i])
        {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        int u;
        cin >> u;
        adj[i + 1].push_back(u);
        adj[u].push_back(i + 1);
    }
    depth[0] = 0;
    dfs(1, -1);
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << endl;
    }
    return 0;
}