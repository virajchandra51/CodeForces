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
        int x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1;
        cin>>x2>>y2;
        cin>>x3>>y3;

        

        if(y1!=y2 && y2!=y3 && y1!=y3)
        {
            cout<<0<<endl;
        }
        else
        {
            if(y1==y2)
            {
                if(y1==0)
                cout<<0<<endl;
                else{
                if(y3<y1)
                cout<<(abs(x2-x1))<<endl;
                else
                cout<<0<<endl;}
            }
            else if(y1==y3)
            {
                if(y1==0)
                cout<<0<<endl;
                else{
                if(y2<y1)
                cout<<(abs(x1-x3))<<endl;
                else
                cout<<0<<endl;}
            }
            else
            {
                if(y2==0)
                cout<<0<<endl;
                else
                {
                if(y1<y2)
                cout<<(abs(x2-x3))<<endl;
                else
                cout<<0<<endl;}
            }
        }

        


    }
    return 0;
}