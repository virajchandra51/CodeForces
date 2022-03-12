#include <bits/stdc++.h>
using namespace std;
#define pi (3.141592653589)
#define mod 1e9+7
#define ll long long int
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
bool comp(pair<int,int> &p1,pair<int,int> &p2)
{
    return p1.second<p2.second;
}
int32_t main()
{
    fast
    //Rating? Neh. In love with experience.
    //Code Karlo, Coz KHNH :)
    
        int n,m;
        cin>>n>>m;
        map<int,vector<pair<int,int>>> mp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int x;
                cin>>x;
                mp[x].push_back({i,j});
            }
        }
      
    
        
        ll ans=0;
        for(auto it:mp)
        {
            vector<pair<int,int>> v = it.second;
            sort(v.begin(),v.end());
           
            ll sum=0;
            for(int i=0;i<v.size();i++) {sum+=v[i].first;}
            for(int i=0;i<v.size();i++)
            {
                sum-=v[i].first;
                ans+= (sum-((v.size()-i-1)*v[i].first));
            }
          
            sum=0;
            sort(v.begin(),v.end(),comp);
            for(int i=0;i<v.size();i++) {sum+=v[i].second;}
            for(int i=0;i<v.size();i++)
            {
                sum-=v[i].second;
                ans+= (sum-((v.size()-i-1)*v[i].second));
            }
        }
        cout<<ans<<endl;


    
    return 0;
}