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
    rep(i,n)
    cin>>a[i];
    map<int,int> mp;
    rep(i,n)
    mp[a[i]]++;
    vi ans;
    for(auto it:mp)
    ans.push_back(it.second);
    sort(ans.begin(),ans.end());
    if(mp.size()==1)
    cout<<ceil(ans[0]*1.0/2)<<endl;
    else if(ans[0]==ans[ans.size()-1])
    cout<<ceil(ans[0])<<endl;
    else if(ceil(ans[ans.size()-1]*1.0/2)>ans[ans.size()-2])
    cout<<ceil(ans[ans.size()-1]*1.0/2)<<endl;
    else
    cout<<ans[ans.size()-2]<<endl;
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