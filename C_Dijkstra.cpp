#include <bits/stdc++.h>
using namespace std;

void Dijkstra(vector<vector<pair<long long, long long> > > &adj, long long n, vector<long long> &dist, vector<long long> &parent)
{
    priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, greater<pair<long long, long long> > > unvisitedNodes;
    unvisitedNodes.push({0, 1});
    dist[1] = 0;
    parent[1] = -1;
    while (!unvisitedNodes.empty())
    {
        long long minDistNode = unvisitedNodes.top().second;
        long long shortestDistToNode = unvisitedNodes.top().first;
        unvisitedNodes.pop();
        for (auto neighbour : adj[minDistNode])
        {
            long long oldDist = dist[neighbour.second];
            long long newDist = shortestDistToNode + neighbour.first;
            if (oldDist > newDist)
            {
                dist[neighbour.second] = newDist;
                unvisitedNodes.push({newDist, neighbour.second});
                parent[neighbour.second] = minDistNode; //
            }
        }
    } // O((n+m)*logn)
}

int main()
{
    long long n, m;
    cin >> n >> m;
    vector<vector<pair<long long, long long> > > adj(n + 1);
    for (int i = 0; i < m; i++) // O(m)
    {
        long long u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back({weight, v});
        adj[v].push_back({weight, u});
    }

    vector<long long> dist(n + 1, LLONG_MAX);
    vector<long long> parent(n + 1, 0);

    Dijkstra(adj, n, dist, parent);

    if (dist[n] == LLONG_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        vector<long long> path;
        path.push_back(n);
        long long curr = n;
        while (parent[curr] != -1)
        {
            path.push_back(parent[curr]);
            curr = parent[curr];
        } // O(m)
        reverse(path.begin(), path.end()); // O(m)
        for (auto it : path)
            cout << it << " ";
        cout << endl;
    }
    
    return 0;
}

// tc - O((n+m)*logn) - O(10^5*17) - O(10^6)
// sc - O(n)