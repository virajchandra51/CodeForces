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
    ll n;
    cin>>n;

    if(__builtin_popcountll(n)==1)
    {
        cout<<-1<<endl;
        return;
    }
    //2n = k(k+1+2p)
    n=n*2;
    ll count = 0;
    while(n%2==0)
    {
        count++;
        n=n/2;
    }
    ll rem = n;
    
    //if k is even
    for(ll i=1;i<=count;i++)
    {
        ll k = (1ll<<i);
        ll rest = (1ll<<(count-i))*rem;
        ll twop = rest - (k+1);
        if(twop>=0 && twop%2==0)
        {
            cout<<k<<endl;
            return;
        }
    }
    //if k is odd
    for(ll i=0;i<=count;i++)
    {
        ll k = (1ll<<i)*rem;
        ll rest = (1ll<<(count-i));
        ll twop = rest - (k+1);
        if(twop>=0 && twop%2==0)
        {
            cout<<k<<endl;
            return;
        }
    }
    cout<<-1<<endl;
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