#include <bits/stdc++.h>

#define pi (3.141592653589)
#define M 1000000007
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
    int a[n];
    rep(i,n)
    cin>>a[i];

    map<int,int> mp;
    rep(i,n)
    mp[a[i]]++;

    int flag=0;
    rep(i,n)
    {
        int diff = a[i]-k;
        if(mp.find(diff)!=mp.end())
        {
            flag=1; break;
        }
    }
   
    if(flag==1)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;

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