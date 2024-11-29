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
    vi a(n);
    rep(i,n)
    cin>>a[i];

    vector<pii> res;

    auto it3 = find(all(a),*max_element(all(a)));
    auto it4 = find(all(a),*min_element(all(a)));
    int difff = abs(a[it3-a.begin()]-a[it4-a.begin()]); int tk = 0;
    if(difff==0)
    {
        cout<<0<<" "<<0<<endl; return;
    }

    rep(i,k)
    {   
        auto it1 = find(all(a),*max_element(all(a)));
        auto it2 = find(all(a),*min_element(all(a)));
        if(it1!=it2)
        {tk++;        
        res.pb({it1-a.begin(),it2-a.begin()});}
        a[it1-a.begin()]--;
        a[it2-a.begin()]++;
        
    }
    auto it1 = find(all(a),*max_element(all(a)));
    auto it2 = find(all(a),*min_element(all(a)));
    int diff = abs(a[it1-a.begin()]-a[it2-a.begin()]);
    cout<<diff<<" "<<tk<<endl;
    rep(i,tk)
    cout<<res[i].f+1<<" "<<res[i].s+1<<endl;

}


int32_t main()
{
    fast
    //Rating? Neh. In love with experience.
    //Code Karlo, Coz KHNH :)

    solve();
    
    return 0;
}