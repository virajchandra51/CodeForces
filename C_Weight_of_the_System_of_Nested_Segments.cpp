#include <bits/stdc++.h>
using namespace std;
#define pi (3.141592653589)
#define mod 1e9+7
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
int32_t main()
{
    fast
    //Rating? Neh. In love with experience.
    //Code Karlo, Coz KHNH :)
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        
        
        vector<pair<int,pair<int,int>>> mpp;

        rep(i,m)
        {
            int p,w;
            cin>>p>>w;
            mpp.push_back({w,{p,i+1}});
        }

        sort(mpp.begin(),mpp.end());
        ll sumw=0;
        vector<pair<int,int>> ans;

        rep(i,2*n)
        {
            sumw+=mpp[i].first;
            ans.push_back(mpp[i].second);
        }

        sort(ans.begin(),ans.end());
        cout<<sumw<<endl;
        
        rep(i,n)
        {
            cout<<ans[i].second<<" "<<ans[2*n-i-1].second<<endl;
        }
        cout<<endl;

    }
    return 0;
}