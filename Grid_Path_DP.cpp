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
    int a[n+1][n+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            char ch;
            cin>>ch;
            if(ch=='.')
            a[i][j]=0;
            else
            a[i][j]=1;
        }
    }

    if(a[n][n]==1 || a[1][1]==1)
    {
        cout<<0<<endl;
        return;
    }
    

    int dp[n+1][n+1];
  
    
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {

            if(i==1 && j==1)
            {dp[i][j]=1; continue;}

            int op1 = j==1 ? 0 : dp[i][j-1];
            int op2 = i==1 ? 0 : dp[i-1][j];
            dp[i][j] = (op1+op2)%M;
            if(a[i][j])
            dp[i][j] = 0;
        }
    }
    cout<<dp[n][n]<<endl;
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