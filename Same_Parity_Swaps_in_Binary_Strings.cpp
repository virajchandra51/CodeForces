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
    string s;
    cin>>s;
    int o=0,z=0;
    rep(i,n)
    {
        if(s[i]=='0')
        z++;
        else
        o++;
    }

    bool pattern1 = true; bool pattern2 = true;
    if(n%2==1)
    n--;
    for(int i=0;i<n-1;i=i+2)
    {
        if(s[i]=='0' && s[i+1]=='1')
        {}
        else
        pattern1 = false;
        if(s[i]=='1' && s[i+1]=='0')
        {}
        pattern2 = false;
    }

    if(pattern1 || pattern2)
    {
        cout<<n/2<<endl;
        return;
    }
    
    if(z<o)
    cout<<z<<endl;
    else if(z>o)
    cout<<o<<endl;
    else
    cout<<o-1<<endl;
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