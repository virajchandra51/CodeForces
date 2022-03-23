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
    
    vi dp(n+1);
    
    
    for(int i=1;i<=n;i++)
    {
        int temp = i;
        int mins = INT_MAX;
        while(temp>0)
        {
            int d = temp%10;
            temp=temp/10;
            if(d==0)
            continue;
            
            mins = min(mins,1+dp[i-d]);
        }
        dp[i]=mins;
    }
    cout<<dp[n]<<endl;

}


int32_t main()
{
    fast
    //Rating? Neh. In love with experience.
    //Code Karlo, Coz KHNH :)
    int t;
    t=1;
    while(t--)
    {
    solve();
    }
    return 0;
}