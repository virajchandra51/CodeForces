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
    int a[n];
    rep(i,n)
    cin>>a[i];
    map<int,int> mp;
    rep(i,n)
    mp[a[i]]++;
    int m = -1; int ans=-1;
    for(auto it:mp)
    {
        if(it.second>m)
        {m=it.second;ans=it.first;}
    }
    int count=0;
    for(auto it:mp)
    {
        if(it.second==m)
        count++;
    }
    if(count>1)
    cout<<"CONFUSED"<<endl;
    else
    cout<<ans<<endl;
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