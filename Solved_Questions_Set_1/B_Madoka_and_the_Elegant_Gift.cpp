#include <bits/stdc++.h>

#define pi (3.141592653589)
#define M 1e9+7
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
    int n,m;
    cin>>n>>m;
    int a[n][m];
    rep(i,n)
        { string s;
        cin>>s;
            rep(j,m)
            { 
                a[i][j]=s[j]-'0';
            }
        }
        
    if(n==1 || m==1)
    cout<<"YES"<<endl;
    else
    {
        
        

        
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<m-1;j++)
            {
                
                int count = a[i][j]+a[i][j+1]+a[i+1][j]+a[i+1][j+1];
                if(count==3)
                {
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
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