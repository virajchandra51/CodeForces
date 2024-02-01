#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void bfs(ll node, vector<ll> &vis, vector<ll> &dist, vector<vector<ll>> &adj)
{
    queue<ll> q;
    q.push(node);
    vis[node] = 1;
    ll distance = 0;
    while (!q.empty())
    {
        ll k = q.size();
        distance++;
        while (k--)
        {
            auto node = q.front();
            q.pop();
            for (auto child : adj[node])
            {
                if (!vis[child])
                {
                    vis[child] = 1;
                    dist[child] = distance;
                    q.push(child);
                }
            }
        }
    }
    return;
}

int main()
{
    ll n;
    cin >> n;

    vector<vector<ll> > adj(n + 1, vector<ll>());
    for (int i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // taking input with edges and creating adj matrix

    vector<ll> marker(n + 1, 0);

    vector<ll> dist(n + 1, 0);
    vector<ll> vis(n + 1, 0);
    bfs(1,vis,dist,adj);
    ll m = max_element(dist.begin(), dist.end()) - dist.begin();
    for(int i=1;i<=n;i++)
        if(dist[i]==dist[m]) marker[i]=1;

    dist = vector<ll>(n + 1, 0);
    vis = vector<ll>(n + 1, 0);
    bfs(m,vis,dist,adj);
    m = max_element(dist.begin(), dist.end()) - dist.begin();
    for(int i=1;i<=n;i++)
        if(dist[i]==dist[m]) marker[i]=1;

    for (int i=1;i<=n;i++)
    {
        if(marker[i]==1) cout<<dist[m]+1<<endl;
        else cout<<dist[m]<<endl;
    }
    return 0;
}

// TC - O(V+E) - O(N+N-1) - O(N)
// SC - O(N+N+N) - O(N)