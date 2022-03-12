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
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ll sum=0; int ans=0;
        int a[n];
        int m = INT_MIN;
        rep(i,n)
        {
            cin>>a[i];
            sum+=a[i];
            m=max(m,a[i]);
        }
        
        sum-=m;
        if((sum+m)==0)
        cout<<0<<endl;
        
        else
        
        {
        
        if(sum>=(m-1))
        ans=1;
        else
        ans=(m-sum);
        
        cout<<ans<<endl;
        }
        
    }
    return 0;
}