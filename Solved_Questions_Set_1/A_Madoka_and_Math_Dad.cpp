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
    int n;
    cin>>n;

    if(n%3==0 || n%3==2)
    {
        while(n>0)
        {
            cout<<2;
            n-=2;
            if(n<=0)
            break;
            cout<<1;
            n--;
        }
        cout<<endl;
    }
    else
    {while(n>0)
        {
            cout<<1;
            n-=1;
            if(n<=0)
            break;
            cout<<2;
            n-=2;
        }
    cout<<endl;
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