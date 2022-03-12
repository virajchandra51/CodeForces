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
       
        int la=INT_MAX,ra=INT_MAX,lb=INT_MAX,rb=INT_MAX;

        rep(i,n)
        {
            la = min(la,abs(a[0]-b[i]));
            ra = min(ra,abs(a[n-1]-b[i]));
            lb = min(lb,abs(b[0]-a[i]));
            rb = min(rb,abs(b[n-1]-a[i]));
        }
        int ans = la+lb;
        int ans1 = ra+rb;
        int ans2 = la+ra;
        int ans3 = lb+rb;
        int ans4 = abs(a[0]-b[0])+abs(a[n-1]-b[n-1]);
        cout<<min(min(min(min(la+lb,abs(a[1]-b[1]))+min(ra+rb,abs(a[n]-b[n])),abs(a[1]-b[n])+abs(a[n]-b[1])),abs(a[1]-b[n])+ra+lb),abs(a[n]-b[1])+la+rb)<<endl;
        cout<<ans<<" "<<ans1<<" "<<ans2<<" "<<ans3<<" "<<ans4<<" "<<endl;
        cout<<min(ans,min(ans1,min(ans2,min(ans3,ans4))));
        
    }
    return 0;
}