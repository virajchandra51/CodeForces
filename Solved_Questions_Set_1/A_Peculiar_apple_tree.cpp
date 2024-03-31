#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    vector<vector<long long> > adj(n + 1, vector<long long>());
    for (int i = 0; i < n - 1; i++)
    {
        long long a;
        cin >> a;
        adj[a].push_back(i + 2);
        adj[i + 2].push_back(a);
    }

    queue<long long> q;
    q.push(1);

    vector<long long> vis(n + 1, false);
    vis[1] = true;

    long long applesCollected = 0;

    while (!q.empty())
    {
        int k = q.size();
        applesCollected += (k % 2);
        while (k--)
        {
            long long node = q.front();
            q.pop();
            for (auto child : adj[node])
            {
                if (vis[child] == false)
                {
                    vis[child] = true;
                    q.push(child);
                }
            }
        }
    }

    cout << applesCollected << endl;
    return 0;
}

// TC - O(V+E) = O(n+n-1) = O(n)
// SC - O(n)
