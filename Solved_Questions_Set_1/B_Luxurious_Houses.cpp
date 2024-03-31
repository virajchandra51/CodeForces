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
    int a[n];
    rep(i,n) cin>>a[i];

    int maxi = a[n-1];
    vector<int> ans;
    ans.push_back(0);
    for(int i=n-2;i>=0;i--)
    {
        
        maxi = max(maxi,a[i+1]);
        if(a[i]<=maxi)
        ans.push_back(maxi-a[i]+1);
    
        else
        ans.push_back(0);


    }
    
    rrep(i,n)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}