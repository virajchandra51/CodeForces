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
        int n;
        cin>>n;
        int a[n];
        rep(i,n) cin>>a[i]; 

        
        sort(a,a+n);
       int ans=1;
        for(int i=0;i<n;i++)
        {
            if(a[i]<=i+1)
            {
                ans=i+2;
            }
        }
        
        cout<<ans<<endl;
    }
    return 0;
}