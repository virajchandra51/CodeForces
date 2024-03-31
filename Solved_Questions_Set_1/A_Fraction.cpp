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
    
        int n;
        cin>>n;
        int a = n/2;
        
        for(int i=a;i>=1;i--)
        {
            int b = n-i;
          
            if(__gcd(i,b)==1)
            {
                cout<<i<<" "<<b<<endl;
                break;
            }
        }
    
    return 0;
}