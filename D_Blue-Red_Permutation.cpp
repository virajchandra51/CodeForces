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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        rep(i,n) cin>>a[i];
        string s;
        cin>>s;

        vector<int>b,r;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='B')
            b.push_back(a[i]);
            else
            r.push_back(a[i]);
        }
        sort(b.begin(),b.end());sort(r.begin(),r.end());

        int flag=1;
        int p=1;
        
        for(int i=0;i<b.size();i++)
        {
            if(b[i]<p)
            {flag=0;break;}
            else
            p++;
        }
        for(int i=0;i<r.size();i++)
        {
            if(r[i]>p)
            {flag=0;break;}
            else
            p++;
        }
        if(flag==0)
        cout<<"NO"<<endl;
        else
        cout<<"YES"<<endl;

    }
    return 0;
}