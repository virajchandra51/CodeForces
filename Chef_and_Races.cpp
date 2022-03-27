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
    vi c(2);
    vi d(2);
    cin>>c[0]>>c[1]>>d[0]>>d[1];
    sort(all(c));
    sort(all(d));

    auto it1 = find(all(d),c[0]);
    auto it2 = find(all(d),c[1]);

    if(it1!=d.end() && it2!=d.end())
    cout<<0<<endl;
    else if((it1!=d.end() && it2==d.end()) || (it1==d.end() && it2!=d.end()))
    cout<<1<<endl;
    else
    cout<<2<<endl;

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