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
    mp[a[i]]=i+1;
    vi ans;
    for(auto it:mp)
    {
        if(it.first!=it.second)
        ans.push_back(abs(it.first-it.second));
    }
    int gcd=ans[0];
    rep(i,ans.size())
    gcd=__gcd(gcd,ans[i]);
    cout<<gcd<<endl;
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