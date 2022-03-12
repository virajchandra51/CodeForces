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
        string s,t;
        cin>>s>>t;
        string w1 = "",w2="";
        for(int i=0;i<t.length();i++)
        w1 = w1+s;
        for(int i=0;i<s.length();i++)
        w2 = w2+t;
        

        if(w1!=w2)
        cout<<-1<<endl;
        else
        {
            int lcm = (t.length()*s.length())/__gcd(t.length(),s.length());
    
            cout<<w1.substr(0,lcm)<<endl;
        }
    }
    return 0;
}