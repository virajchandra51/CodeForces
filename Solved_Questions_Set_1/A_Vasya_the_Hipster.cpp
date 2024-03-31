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
    
        int a,b;
        cin>>a>>b;
        if(a==b)
        cout<<a<<" "<<0<<endl;
        else if(a>b)
        cout<<b<<" "<<(a-b)/2<<endl;
        else
        cout<<a<<" "<<(b-a)/2<<endl;
    
    return 0;
}