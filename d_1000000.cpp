#include <bits/stdc++.h>
using namespace std;
#define pi (3.141592653589)
#define mod 1e9+7
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define vi vector<int>
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int32_t main()
{
    fast
    //Rating? Neh. In love with experience.
    //Code Karlo, Coz KHNH :)
    
    int t; int i=1;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    int a[n];
    rep(i,n)
    cin>>a[i];
    sort(a,a+n);
    int counter=1;
    rep(i,n)
    {
        if(a[i]>=counter)
        counter++;
    }
    
    cout<<"Case #"<<i<<": "<<counter-1<<endl;
    i++;
    }
    return 0;
}