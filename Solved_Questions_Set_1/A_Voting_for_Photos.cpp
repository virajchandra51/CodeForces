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
int32_t main()
{
    fast
    //Rating? Neh. In love with experience.
    //Code Karlo, Coz KHNH :)
    
    int n;
    cin>>n;
    
    int arr[1000009] = {0};
    int ans=INT_MIN,c=INT_MIN;
    
    rep(i,n)
    {
        int x;
        cin>>x;
        arr[x]++;
        if(arr[x]>c)
        {
            c=arr[x];
            ans=x;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}