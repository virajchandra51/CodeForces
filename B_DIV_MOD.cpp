#include <bits/stdc++.h>
using namespace std;
#define pi (3.141592653589)
#define mod 1e9+7
#define ll long long int
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
        ll l,r,a;
        cin>>l>>r>>a;

        if(a>r)
        {
            cout<<r<<endl;
        }
        
        
        else
        { 
        ll fac = r/a;
        ll aa = a*fac;
        
        ll ans = floor(r/(double)a)+r%a;
        if(aa<=l)
        {
            
            cout<<ans<<endl;
        }
        else
        {
            ll ans1=floor((aa-1)/(double)a)+((aa-1)%a);
            cout<<max(ans1,ans)<<endl;
            
        }
        }
        
    }
    return 0;
}