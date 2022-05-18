#include <bits/stdc++.h>
using namespace std;

//Speed
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

//Macros
#define rep(i,j) for(int i=0;i<j;i++)
#define rrep(i,j) for(int i=j-1;i>=0;i--)
#define all(x) x.begin(), x.end()

//Typedef
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef map<int,int> mii;

void answertoProb()
{
    int n;
    cin>>n;
    vi a(n);
    vi b(n);
    map<int,pair<int,int>> dd;
    for(auto it: dd)
    {
        cout<<it.second.first<<endl;
        cout<<it.second.second<<endl;
    }
    int num=1;
    while(a.size()<n-1)
    {
        ll c = num^(num+1);
        if(dd[c].first==0 && dd[c].second==0)
        {
            dd[c].first=num;
            dd[c].second=num+1;
            num+=2;
        }
        else
        {
            a.push_back(dd[c].first);
            a.push_back(dd[c].second);
            b.push_back(num);
            b.push_back(num+1);
            num+=2;
            dd[c].first=0;
            dd[c].second=0;
        }
    }
    if(n&1)
    {
        a.push_back(num+4);
        b.push_back(num+5);
    }

    rep(i,n)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    rep(i,n)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
}


int32_t main()
{
    fastio()
    int t;
    cin>>t;
    while(t--)
    {
    answertoProb();
    }
    return 0;
}