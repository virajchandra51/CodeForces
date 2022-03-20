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
    if(n==1)
    {cout<<1<<endl; return;}
    int c1=0,c2=0,c3=0,ans=0;
    rep(i,n)
    {   
        int x;
        cin>>x;
        if(x==1)
        c1++; 
        else if(x==2)
        c2++; 
        else if(x==3)
        c3++; 
        else
        ans++; 
    }

    if(c3>=c1)
    {
        ans+=c1;
        c3-=c1;
        ans+=c3;
        ans+= (c2/2) + (c2%2);
        cout<<ans<<endl;
    }
    else
    {
        ans+=c3;
        c1-=c3;
        ans+= (c2/2);
        c2=c2%2;
        if(c2==1 && c1>=2)
        {
            ans++;
            c2=0;
            c1=c1-2;
            ans+= (c1/4);
            if(c1%4>0)
            ans++;
        }
        else if(c2==1 && c1<2)
        {
            ans++;
        }
        else
        {

            ans+= (c1/4);
            if(c1%4 >0)
            ans++;
        }
        cout<<ans<<endl;
    }

}


int32_t main()
{
    fast
    //Rating? Neh. In love with experience.
    //Code Karlo, Coz KHNH :)
   
 
    
    solve();
    
    return 0;
}