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
        string s;
        cin>>s;
        int i1=0,i2=0,i3=0,i4=0,i5=0,i6=0 ;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='r')
            i1=i;
            else if(s[i]=='b')
            i2=i;
            else if(s[i]=='g')
            i3=i;
            else if(s[i]=='R')
            i4=i;
            else if(s[i]=='B')
            i5=i;
            else
            i6=i;
        }

        if(i1<i4 && i2<i5 && i3<i6)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;

    }
    return 0;
}