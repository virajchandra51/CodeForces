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
    string s;
    cin>>s;
    int c=0;
    int n = s.length();
    for(int i=0;i<n;i++)
    {
        if(s[i]=='Q')
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[j]=='A')
                {
                    for(int k=j+1;k<n;k++)
                    {
                        if(s[k]=='Q')
                        c++;
                    }
                }
            }
        }
    }
    cout<<c<<endl;
}


int32_t main()
{
    fast
    //Rating? Neh. In love with experience.
    //Code Karlo, Coz KHNH :)
    
    solve();
    
    return 0;
}