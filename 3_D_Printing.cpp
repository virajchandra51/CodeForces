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


int32_t main()
{
    fast
    //Rating? Neh. In love with experience.
    //Code Karlo, Coz KHNH :)
    int t;
    cin>>t;
    int i=1;
    while(t--)
    {
    int c[3],m[3],y[3],b[3];
    int minc=INT_MAX,minm=INT_MAX,miny=INT_MAX,minb=INT_MAX;
    rep(i,3)
    {
        cin>>c[i]>>m[i]>>y[i]>>b[i];
        minc = min(minc,c[i]);
        minm = min(minm,m[i]);
        miny = min(miny,y[i]);
        minb = min(minb,b[i]);
    }
    if((minc+minm+minb+miny)<1000000)
    {
        cout<<"Case #"<<i<<": "<<"IMPOSSIBLE"<<endl;
        i++;    
    }
    else if((minc+minm+minb+miny)==1000000)
    {
        cout<<"Case #"<<i<<": "<<minc<<" "<<minm<<" "<<miny<<" "<<minb<<endl;
        i++;
    }
    else
    {
        int all_min[4];
        all_min[0]=minc,all_min[1]=minm,all_min[2]=miny,all_min[3]=minb;
        int res[4] = {0};
        int mainvalue=1000000;
        for(int in=0;in<4;in++)
        {
            if(all_min[in]<=mainvalue)
            {
                res[in]=all_min[in];
                mainvalue-=all_min[in];
            }
            else
            {
                break;
            }
        }
        if(mainvalue==0)
        {
            cout<<"Case #"<<i<<": "<<res[0]<<" "<<res[1]<<" "<<res[2]<<" "<<res[3]<<endl;
            i++;
        }
        else
        {
            int mres[4] = {0};
            rep(i,4)
            {
                if(res[i]!=0)
                mres[i]=res[i];
                else
                {
                    mres[i] = mainvalue;
                }
            }
            cout<<"Case #"<<i<<": "<<mres[0]<<" "<<mres[1]<<" "<<mres[2]<<" "<<mres[3]<<endl;
            i++;
        }
    }
    }
    return 0;
}
