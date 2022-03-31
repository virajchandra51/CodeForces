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
    int n;
    cin>>n;
    string s;
    cin>>s;

    int z=0,o=0;
    rep(i,n)
    {
        if(s[i]=='0')
        z++;
        else
        o++;
    }
    if(z==n || o==n)
    {
        cout<<s<<endl;
        cout<<s<<endl;
        return;
    }
    if(o>z)
    {
        int division = (o-1)/(z+1);
        if(division==0)
        {
            cout<<1;
            int ref=z;
            if(o-1==z)
            {
                while(ref--)
                cout<<1<<0;
            }
            else
            {
                cout<<1;
            }
            cout<<endl;
        }
        else
        {
            int ref = o-division*z;
            while((ref-division)>1)
            {
                division++;
                ref = o-division*z;
            }
            int ref2=z;
            int rref = ref;
            if(ref>0)
            {
                while(rref--)
                cout<<1;
            }
            int pqr = ref2;
            if(ref<0)
            pqr = ref2+ref;
            while(pqr--)
            {
                int ref3 =division;
                cout<<0;
                while(ref3--)
                cout<<1;
            }
            if(ref<0)
            {int pt=-ref;
            while(pt--)
            {
                int ref3 = division-1;
                cout<<0;
                while(ref3--)
                cout<<1;
            }
            }
            cout<<endl;
        }
        int ref1 = o,ref0=z;
        while(ref0--)
        cout<<0;
        while(ref1--)
        cout<<1;
        cout<<endl;
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