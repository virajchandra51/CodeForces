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
    string s;
    cin>>s;

    int ansf=0;
    for(int i=0;i<s.length();)
    {
        if(i==s.length()-1)
        {
            ansf++;
            break;
        }
        if(s[i]==s[i+1])
        i+=2;
        else
        {
            set<char> st;
            int current_i=i;
            int flag=0;
            while(i<s.length())
            {
                if(st.find(s[i])!=st.end())
                {
                    flag=1;
                    break;
                }
                st.insert(s[i]);
                i++;
            }
            if(i==s.length() || !flag) 
            ansf+=(i-current_i);
            else 
            ansf+= (i-current_i-1);
            i++;
        }
    }
    cout<<ansf<<endl;
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