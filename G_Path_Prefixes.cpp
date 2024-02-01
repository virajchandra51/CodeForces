#include <bits/stdc++.h>
using namespace std;

void dfs(long long node, vector<vector<long long>> &adj, vector<long long>& aValues, vector<long long> &bValues, long long aSum, long long bSum, vector<long long> &answerR, vector<long long> &prefixB)
{
    for(auto child:adj[node])
    {
        aSum+=aValues[child];
        bSum+=bValues[child];
        prefixB.push_back(bSum);
        answerR[child] = upper_bound(prefixB.begin(), prefixB.end(), aSum) - prefixB.begin();
        dfs(child,adj,aValues,bValues,aSum,bSum,answerR,prefixB);
        aSum-=aValues[child];
        bSum-=bValues[child];
        prefixB.pop_back();
    }
}

int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        vector<vector<long long>> adj(n+1,vector<long long>());
        vector<long long> aValues(n+1,0);
        vector<long long> bValues(n+1,0);
        for(long long i=0;i<n-1;i++)
        {
            long long p,a,b;
            cin>>p>>a>>b;
            adj[p].push_back(i+2);
            aValues[i+2] = a;
            bValues[i+2] = b;
        }
        long long aSum = 0;
        long long bSum = 0;
        vector<long long> prefixB;
        vector<long long> answerR(n+1);
        dfs(1,adj,aValues,bValues,aSum,bSum,answerR,prefixB);
        for(long long i=2;i<=n;i++) cout<<answerR[i]<<" ";
        cout<<endl;
    }
    return 0;
}