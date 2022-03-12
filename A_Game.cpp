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
        int a[n]; int c=0;
        rep(i,n)
        {
            cin>>a[i];
            if(a[i]==1)
            c++;
        }
        
        int l=0;int r=0;
        for(int i=1;i<n;i++)
        {
            if(a[i]-a[i-1]!=0)
            {l=i-1; break;}
        }
        for(int i=n-2;i>0;i--)
        {
            if(a[i+1]-a[i]!=0)
            {
                r=i; break;
            }
        }
        
        
        cout<<(c==n?0:(r-l+1))<<endl;
       
    }
    return 0;
}