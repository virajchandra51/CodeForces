#include <bits/stdc++.h>
using namespace std;
#define pi (3.141592653589)
#define mod 1e9+7
#define ll long long int
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
bool same(int a[],int n)
{
    for(int i=1;i<n;i++)
    {if(a[i]!=a[i-1])
    return false;}

    return true;
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
        int n;
        cin>>n;
        int a[n];
        rep(i,n) cin>>a[i];

        int a1 = a[0];
        int a2 = a[0];

        for(int i=0;i<n;i++)
        {
            a1 = a1&a[i];
            a2 = a2|a[i];

        }
      

        int a3 = a1|a2;
        int index = 0;
        ll ans=0;
        while(a3>0)
        {
            if(a3%2==1)
            {
                ans=ans+ pow(2,index);
                a3 = a3/2;
                index++;
            }
            else
            {
                a3=a3/2;
                index++;
            }
        }
        cout<<ans<<endl;


    }
    return 0;
}