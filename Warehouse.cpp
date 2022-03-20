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
    int bz;
    cin>>bz;
    int b[bz];
    rep(i,bz)
    cin>>b[i];
    int ubz;
    cin>>ubz;
    int ub[ubz];
    rep(i,ubz)
    cin>>ub[i];
    int tz;
    cin>>tz;
    
    vector<pii> p;

    rep(i,bz)
    {
        p[i].f = ub[i];
        p[i].s = b[i];
    }
    sort(p.rbegin(), p.rend());

    int count = 0; int index=0;
    while(tz>0)
    {
        if(p[index].s<=tz)
        {
            count = count + (p[index].s*p[index].f);
            tz = tz - p[index].s;
            index++;
        }
        else
        {
            count = count + (tz*p[index].f);
            tz = 0;
        }
    }
    cout<<count<<endl;



}


int32_t main()
{
    fast
    //Rating? Neh. In love with experience.
    //Code Karlo, Coz KHNH :)
    
    
    solve();
    
    return 0;
}