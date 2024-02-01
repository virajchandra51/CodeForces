#include <bits/stdc++.h>
using namespace std;

long long farthestNode;

void diameterHelper(long long par, long long node, long long distance, long long &maxDistance, vector<vector<long long>> &adj)
{
    distance++;
    for(auto child:adj[node])
    {
        if(child==par) continue;
        else
        {
            if(distance>maxDistance)
            {
                maxDistance = distance;
                farthestNode = child;
            }
            diameterHelper(node,child,distance,maxDistance,adj);
        }
    }
    return;
}

int main()
{
    long long n;
    cin >> n;

    vector<vector<long long>> adj(n+1,vector<long long>());
    for(int i=0;i<n-1;i++)
    {
        long long a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    long long maxDistance = 0;
    diameterHelper(-1,1,0,maxDistance,adj); // X = 1
    maxDistance = 0;
    diameterHelper(-1,farthestNode,0,maxDistance,adj);
    cout<<maxDistance<<endl;

    return 0;
}

// TC - O(V+E) = O(n+n-1) = O(n)

