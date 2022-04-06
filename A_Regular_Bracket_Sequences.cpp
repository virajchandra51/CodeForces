#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

#define PI (3.141592653589)
#define M 1000000007
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define foreach(i, j, k, in) for(int i=j;i<k;i+=in)
#define rforeach(i, j, k, in) for(int i=j;i>=k;i-=in)
#define rep(i,j) foreach(i,0,j,1)
#define rrep(i,j) rforeach(i,j,0,1)
#define set_bits __builtin_popcountll
#define all(x) x.begin(), x.end()
#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl
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

#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" ";_print(x); cerr<<endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

void solve()
{
    int n;
    cin>>n;
    int temp=n;
    rep(i,n)
    {
        for(int j=1;j<=temp;j++)
        cout<<'(';
        for(int j=1;j<=temp;j++)
        cout<<')';
        int diff=n-temp;
        if(temp==1)
        {
            for(int j=1;j<=diff;j++)
            cout<<"()";
        }
        else
        {
            for(int j=1;j<=diff;j++)
            cout<<'(';
            for(int j=1;j<=diff;j++)
            cout<<')';
            temp--;
        }
        cout<<endl;
    }
}


int32_t main()
{
    fastio()
    #ifndef ONLINE_JUDGE
        freopen("Error.txt","w",stderr);
    #endif
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