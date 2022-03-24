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
    int n;
    cin>>n;

    int a[n];
    rep(i,n)
    {
        cin>>a[i];
    }

    int maxi = INT_MIN;
    int mini = INT_MAX;

    int i1=-1,i2=-1;
    rep(i,n)
    {
        if(a[i]>maxi)
        {maxi=a[i];i1=i+1;}
        if(a[i]<mini)
        {mini=a[i];i2=i+1;}
    }
    cout<<min(i1,i2)<<" "<<max(i1,i2)<<endl;
    
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