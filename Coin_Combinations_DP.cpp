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
    int n,x;
    cin>>n>>x;
    vi a(n+1);
    for(int i=1;i<=n;i++)
    cin>>a[i];

    int dp[n+1][x+1];
   
    for(int i=1;i<=n;i++)
    {
        for(int sum = 0;sum<=x;sum++)
        {
            if(sum==0)
            dp[i][sum]=1;
            else
            {
                int op1 = (a[i]>sum)?0:dp[i][sum-a[i]];
                int op2 = (i==1)?0:dp[i-1][sum];
                dp[i][sum] = (op1 + op2)%M;
            }
        }
    }
    cout<<dp[n][x]<<endl;

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