#include <bits/stdc++.h>
using namespace std;
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

ll mini(ll a, ll b)
{
    if(a>b) return b;
    else
    return a;
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
        int n;
        cin>>n;
        int a[n],b[n];
        rep(i,n)
        {
            cin>>a[i];
        }
        rep(i,n)
        {
            cin>>b[i];
        }
       
        ll la = 1e9+7;
        ll ra = 1e9+7;
        ll lb = 1e9+7;
        ll rb = 1e9+7;


        rep(i,n)
        {
            la = mini(la,abs(a[0]-b[i]));
            ra = mini(ra,abs(a[n-1]-b[i]));
            lb = mini(lb,abs(b[0]-a[i]));
            rb = mini(rb,abs(b[n-1]-a[i]));
        }
      
        int ans = abs(a[0]-b[0])+abs(a[n-1]-b[n-1]);
        ans = mini(ans,abs(a[0]-b[n-1])+abs(a[n-1]-b[0]));
        ans = mini(ans,abs(a[0]-b[0])+ra+rb);
        ans = mini(ans,abs(a[n-1]-b[n-1])+la+lb);
        ans = mini(ans,abs(a[0]-b[n-1])+lb+ra);
        ans = mini(ans,abs(a[n-1]-b[0])+la+rb);
        ans = mini(ans,la+lb+ra+rb);
        cout<<ans<<endl;
        
        
        
    }
    return 0;
}