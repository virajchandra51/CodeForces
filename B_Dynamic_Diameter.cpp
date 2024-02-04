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
    // running bfs from arbitary node 1 to find some potential ends of diameter
    bfs(1,vis,dist,adj);

    // taking any one node from the highest distance from node 1 as farthest node
    ll farthestNode = max_element(dist.begin(), dist.end()) - dist.begin();

    // mark all the nodes as ends of diameter which have greates distance
    for(int i=1;i<=n;i++)
        if(dist[i]==dist[farthestNode]) marker[i]=1;

    dist = vector<ll>(n + 1, 0);
    vis = vector<ll>(n + 1, 0);
    // running bfs again from farthest node to find the other left over potential ends of diameter
    bfs(farthestNode,vis,dist,adj);

    // taking the first node having the highest distance from vector as farthest node
    farthestNode = max_element(dist.begin(), dist.end()) - dist.begin();

    // mark all nodes as ends of diameter again
    for(int i=1;i<=n;i++)
        if(dist[i]==dist[farthestNode]) marker[i]=1;

    // for all the nodes which are ends of diameter answer = diameter + 1
    // else answer = diameter
    for (int i=1;i<=n;i++)
    {
        if(marker[i]==1) cout<<dist[farthestNode]+1<<endl;
        else cout<<dist[farthestNode]<<endl;
    }
    return 0;
}

// TC - O(V+E) - O(N+N-1) - O(N)
// SC - O(N+N+N) - O(N)