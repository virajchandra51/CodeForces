#include <bits/stdc++.h>
using namespace std;
#define pi (3.141592653589)
#define mod 1e9+7
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define f first
#define s second
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
        vector<int> a(n);
        rep(i,n)
        {
            cin>>a[i];
        }

        vector<int> ans(n);

        for(int i =n;i>=1;i--)
        {
            auto it = find(all(a),i);
            ans[i-1] = (it-a.begin()+1)%i;
            rotate(a.begin(),it,a.end());
            a.erase(a.begin());
        }
        rep(i,n)
        cout<<ans[i]<<" ";
        cout<<endl;


    }
    return 0;
}