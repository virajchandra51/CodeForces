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
    int n;
    cin>>n;
    vi a(n);vi e,o;
    rep(i,n)
    {
        cin>>a[i];
        if(a[i]%2==0)
        e.pb(a[i]);
        else
        o.pb(a[i]);
    }
    if(o.size()==1)
    {
        auto it = find(all(a),o[0]);
        cout<<it-a.begin()+1<<endl;
    }
    else
    {
        auto it = find(all(a),e[0]);
        cout<<it-a.begin()+1<<endl;
    } 
}


int32_t main()
{
    fast
    //Rating? Neh. In love with experience.
    //Code Karlo, Coz KHNH :)
    
    solve();
    
    return 0;
}