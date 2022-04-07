#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

#define PI (3.141592653589)
#define M 1000000007
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define foreach(i, j, k, in) for(int i=j;i<k;i+=in)
#define rforeach(i, j, k, in) for(int i=j;i>=k;i-=in)
#define rep(i,j) foreach(i,0,j,1)
#define rrep(i,j) rforeach(i,j,0,1)
#define ps(x,y) fixed<<setprecision(y)<<x

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int,int> mp;
typedef set<int> st;

void solve()
{
    int n;
    cin>>n;
    int a[n];
    rep(i,n) cin>>a[i];
    if(n==3 && a[1]%2==1)
    {
        cout<<-1<<endl;return;
    }
    int flag=1; ll ans=0;
    foreach(i,1,n-1,1)
    {
        if(a[i]>1)
        {
            flag=0;
        }
        ans+=ceil(a[i]/2.0);
    }
    cout<<(flag==0?ans:-1)<<endl;
}


int32_t main()
{
    fastio()
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