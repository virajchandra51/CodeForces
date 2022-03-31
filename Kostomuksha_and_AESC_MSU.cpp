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
    ll n,x;
    cin>>n>>x;
    vi a(n); 
    rep(i,n)
    cin>>a[i];

    bool eq = true;
    for(int i=1;i<n;i++)
    {
        if(a[i]!=a[i-1])
        {
            eq=false;
            break;
        }
    }
    
    ll res=0;

    if(eq)
    {
        if(a[0]==x)
        {
            res+=(n*(n+1))/2;
            cout<<res<<endl;
            return;
        }
    }
    else
    {
        rep(i,n)
        {
            double pro = (a[i]*1.0)/x;
            for(int j=i+1;j<=n;j++)  
            {
                if(pro==1)
                res++;
                if(j!=n)
                pro = (pro*a[j]*1.0)/x;
            }
        }
    }
    cout<<res<<endl;
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