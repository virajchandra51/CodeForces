#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define REP(i, k, n) for (int i = k; i < n; i++)
#define REPREV(i, k, n) for (int i = n - 1; i >= k; i--)
#define pii pair<int, int>
#define vpi vector<pair<int, int>>
#define vi vector<int>
#define sortv(v) sort(v.begin(), v.end())
#define sortrev(v) sort(v.begin(), v.end(), greater<int>())
#define int long long int

signed main()
{
    fast;
    int t;
    cin >> t;
    REP(i, 0, t)
    {
        int n, a, b;
        cin >> n >> a >> b;
        string x, y;
        cin >> x >> y;
        int cnt = 0;
        vi v;
        REP(i, 0, n)
        {
            if (x[i] != y[i])
            {
                cnt++;
                v.pb(i);
            }
        }
        if (cnt % 2 != 0)
        {
            cout << -1 << endl;
        }
        else if (x==y)
        {
            cout<<0<<endl;
            /* code */
        }
        
        else
        {
            int cntt = 0;
            REP(i, 0, v.size() - 1)
            {
                if (v[i + 1] - v[i] == 1)
                {
                    cntt++;
                    i++;
                }
            }
            if (cntt==1 &&v.size()==2)
            {
                int ans1=a;
                int ans2=2*b;
                cout<<min(ans1,ans2)<<endl;
            }
            else
            {
                int pp=v.size()/2;
                pp-=cntt;
                int ans1=(cntt*a)+(pp*b);
                int ppp=v.size()/2;
                int ans2=ppp*b;
                int ans=min(ans1,ans2);
                cout<<ans<<endl;
            }
            
            
            
        }
    }
}