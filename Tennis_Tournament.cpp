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

void solve()
{
        int n;
        cin>>n;
        if(n%2==0)
        cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            int nones = n/2;
            
            vector<int> a(n);
            
            for(int i=0;i<nones;i++)
            a[i]=1;
            for(int i=nones;i<n;i++)
            a[i]=0;
            
            for(int j=1;j<=n;j++)
            {
            rotate(a.begin(),a.begin()+a.size()-1,a.end());
            
            for(int i=0;i<n;i++)
            cout<<a[i];
            
            cout<<endl;}
            
        }
}


int32_t main()
{
    fast
    //Rating? Neh. In love with experience.
    //Code Karlo, Coz KHNH :)
    int t;
    cin>>t;
    while(t--)
    {
    solve();
    }
    return 0;
}