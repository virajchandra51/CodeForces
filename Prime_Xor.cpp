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
    ll x,y;
    cin>>x>>y;
    int a,b;
    if(!(x&1))
    {
        a=2^y;
        b=a^x;
    }
    else if(!(y&1))
    {
        a=2^x;
        b=a^y;
    }
    else
    {
        a=2^x;
        b=2^y;
    }
    cout<<2<<" "<<min(a,b)<<" "<<max(a,b)<<endl;
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