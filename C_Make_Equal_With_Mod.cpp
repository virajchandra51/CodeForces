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
    int a[n]; int zc=0,oc=0; int eq=1; 
    rep(i,n)
    {
        cin>>a[i];
        if(a[i]==1)
        oc++;
        if(a[i]==0)
        zc++;
        if(i!= 0 && a[i] != a[i-1])    
        eq=0; 
    }

    sort(a,a+n);

    if(eq==1)
    {
        cout<<"YES"<<endl;
    }
    else if(zc>0 && oc>0)
    {
        cout<<"NO"<<endl;
    }
    else if(oc>0)
    {
        int flag = 0;
        for(int i=1;i<n;i++)
        {
            if(a[i]-a[i-1] == 1)
            {
            flag=1;
            }
        }
        if(flag)
        cout<<"NO"<<endl;
        else
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
    }
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