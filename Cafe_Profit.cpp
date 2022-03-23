#include <bits/stdc++.h>

#define pi (3.141592653589)
#define M 1000000007
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
    int startday[3][2];
    int endday[3][2];
    double profit[3];
    cout<<"ENTER START DAY MATRIX"<<endl;
    rep(i,3)
    {
        rep(j,2)
        cin>>startday[i][j];
    }
    cout<<"ENTER END DAY MATRIX"<<endl;
    rep(i,3)
    {
        rep(j,2)
        cin>>endday[i][j];
    }
    cout<<"ENTER PROFIT MATRIX"<<endl;
    cin>>profit[0]>>profit[1]>>profit[2];
    double totalp = 0.0;

    for(int i=0;i<3;i++)
    {
        for(int j = 0;j<2;j++)
        {
            totalp = totalp + (startday[i][j]-endday[i][j])*profit[i];
        }
    }
    cout<<totalp<<endl;

}


int32_t main()
{
    fast
    //Rating? Neh. In love with experience.
    //Code Karlo, Coz KHNH :)
    int t;
    t=1;
    while(t--)
    {
    solve();
    }
    return 0;
}