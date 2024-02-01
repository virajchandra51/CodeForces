#include <bits/stdc++.h>
using namespace std;

long long roadHelper(long long par, long long node, vector<vector<long long> > &adj, vector<long long> &subTreeSum, vector<long long> &roads)
{
    if (roads[node] == 1)
        subTreeSum[node]++;
    for (auto child : adj[node])
    {
        if (child == par)
            continue;
        subTreeSum[node] += roadHelper(node, child, adj, subTreeSum, roads);
    }
    return subTreeSum[node];
}

int main()
{
    long long n;
    cin >> n;

    vector<vector<long long> > adj(n + 1, vector<long long>());
    vector<long long> roads(n + 1, 0);
    for (int i = 0; i < n - 1; i++)
    {
        long long a, b, r;
        cin >> a >> b >> r;
        adj[a].push_back(b);
        adj[b].push_back(a);
        if (r == 2)
        {
            roads[a] = 1;
            roads[b] = 1;
        }
    }

    vector<long long> subTreeSum(n + 1, 0);
    roadHelper(-1, 1, adj, subTreeSum, roads);
    vector<long long> candidates;
    for (int i = 0; i < subTreeSum.size(); i++)
    {
        if (subTreeSum[i] == 1)
            candidates.push_back(i);
    }
    cout << candidates.size() << endl;
    for (auto it : candidates)
        cout << it << " ";
    cout << endl;
    return 0;
}

// TC - O(V+E) = O(n+n-1) = O(n)
// SC - O(n)
