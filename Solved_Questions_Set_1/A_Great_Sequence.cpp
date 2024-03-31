#include <bits/stdc++.h>

#define pi (3.141592653589)
#define M 1e9+7
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define ps(x,y) fixed<<setprecision(y)<<x
#define pii pair<int,int>
#define vi vector<int>

using namespace std;

void solve()
{
    int n,k;
    cin>>n>>k;
    map<ll,ll> mp;
    rep(i,n)
    {
        int x;
        cin>>x;
        mp[x]++;
    }
    
    for(auto it: mp)
    {
        if(it.s==0)
        continue;
        if(mp.find((it.f)*k)!=mp.end())
        {
            if(it.s > mp[(it.f)*k])
            {
                mp[it.f] = mp[it.f] - mp[(it.f)*k];
                mp[(it.f)*k] = 0;
            }
            else
            {
                mp[(it.f)*k] = mp[(it.f)*k] - it.s;
                mp[it.f] = 0;
            }  
        }
    }
   
    int c=0;
    for(auto it:mp)
    {
        if(it.s>0)
        c=c+it.s;
    }
    cout<<c<<endl;
}


int32_t main()
{
    fast
    //Rating? Neh. In love with experience.
    //Code Karlo, Coz KHNH :)
    int t;
    cin>>t;
    while(t--)
    {
    solve();
    }
    return 0;
}