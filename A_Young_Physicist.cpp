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
    int a[n][3]; int ar=0,b=0,c=0;
    rep(i,n)
    {
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        ar+=a[i][0]; b+=a[i][1]; c+=a[i][2];
    }
    

    if(ar==0 && b==0 && c==0)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;


}


int32_t main()
{
    fast
    //Rating? Neh. In love with experience.
    //Code Karlo, Coz KHNH :)
    
    solve();
    
    return 0;
}