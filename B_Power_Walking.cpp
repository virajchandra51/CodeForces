#include <bits/stdc++.h>
using namespace std;
#define pi (3.141592653589)
#define mod 1e9+7
#define ll long long int
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
long long int big= 1e9;
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
        set<int> s;
        vector<int> sf;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            s.insert(a[i]);
        }

        int start = s.size(); int loopsize = s.size();
        
        unordered_map<int, int> mp;
 
    // Traverse through array elements and
    // count frequencies
        for (int i = 0; i < n; i++)
        mp[a[i]]++;

       for (int i = 0; i < n; i++) {
        if (mp[a[i]] != -1)
        {
          sf.push_back(mp[a[i]]);
          mp[a[i]] = -1;
        }
        }

        sort(sf.begin(),sf.end());

        cout<<start<<" ";
        int starti=1;
        for(int i=0;i<sf.size()-1;i++)
        {
            if(sf[i]==starti)
            cout<<start<<" ";
            else
            {   start++;
                for(int j=sf[i];j>=1;j--)
                {
                
                    cout<<start<<" ";
                }
            }


        }
        
        for(int i=sf[sf.size()-1];i>1;i--)
        {
            start++;
            cout<<start<<" ";
        }
        cout<<""<<endl;
        
    }
    return 0;
}