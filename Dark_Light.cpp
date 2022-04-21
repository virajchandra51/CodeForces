#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

typedef long long ll;

void solve()
{
    ll n,k;
    cin >> n >>k;
    if(k==0)
    {
        if((n%4)==0)
        cout<<"Off"<<endl;
        else
        cout<<"On"<<endl;
    }
    else
    {
        if(n%4==0)
        cout<<"On"<<endl;
        else
        cout<<"Ambiguous"<<endl;
    }
}


int32_t main()
{
    fastio()
    #ifndef ONLINE_JUDGE
        freopen("Error.txt","w",stderr);
    #endif
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