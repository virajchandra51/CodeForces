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

        vector<int> odd;
        vector<int> even;

        for (int i = 0; i < n; i++)
        {
            if(a[i]%2==1)
            odd.push_back(a[i]);
            else
            even.push_back(a[i]);
        }

        int flag=0;

        for (int i = 1; i < odd.size(); i++)
        {
            if(odd[i]<odd[i-1])
            {flag = 1;break;}
        }
        
        for (int i = 1; i < even.size(); i++)
        {
            if(even[i]<even[i-1])
            {flag = 1;break;}
        }
        if(flag==1)
        cout<<"No"<<endl;
        else
        cout<<"Yes"<<endl;
    }
    return 0;
}