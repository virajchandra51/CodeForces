#include <bits/stdc++.h>
using namespace std;

int32_t main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int> > adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b); // a--> b path exist kore
    }
    vector<vector<vector<int> > > dp(n + 1);
    vector<int> vis(n + 1, 0);
    // dp[i]--> all path  from 1 to i node .. each path stored as vector
    // vector<int>maxpath(n+1,-1);
    queue<int> q;
    q.push(1);            //
    dp[1].push_back({1}); //
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto &v : adj[u])
        { // it->neighbour of top
            // if(dp[v]==-1) q.push(v);
            // dp[v]= max(dp[v],dp[u]+1);//
            // if(dp[v]==dp[u]+1) maxpath[v]=u;
            for (auto &it : dp[u])
            { // dp[u]--> 2d vector
                // ai step ta optimiseation kora jata pare
                // it--> 1d vector
                vector<int> aa = it;
                aa.push_back(v);
                dp[v].push_back(aa);
                // dp[v] ar modhya new all paths from [1->u] +v storage
                //
            }
            /// if(!vis[v])
            q.push(v);
        }
    }
    vector<int> vis2(n + 1, 0);
    set<int> s;
    int anss = 0;
    for (auto &paths : dp[n])
    { // vec
        int ff = 1;
        for (auto &path : paths)
        {
            if (s.find(path) != s.end())
                ff = 0;
        }
        if (ff)
        {
            for (auto &path : paths)
            {
                if (path == 1 || path == n)
                { // anss++;
                    continue;
                }
                else
                {
                    s.insert(path);
                    // anss++;
                }
                // else
            }
            anss++;
        }
        //  cout<<endl;
    }
    cout << anss << endl;

    for (auto &paths : dp[n])
    { // vec
        int f = 1;
        for (auto &path : paths)
        {
            if (path == 1 || path == n)
                continue;
            else if (vis2[path])
                f = 0;
            // cout<<path<<" ";
        }
        if (f)
        {
            cout << paths.size() << endl;
            for (auto &path : paths)
            {
                if (path != 1 || path != n)
                    vis2[path] = 1;
                cout << path << " ";
            }
            cout << endl;
        }
    }
}
