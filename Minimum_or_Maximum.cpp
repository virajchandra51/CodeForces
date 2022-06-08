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
    int mx = a[0];
    int mn = a[0];
    bool f = true;
    rep(i,n)
    {
        if(a[i]>=mx)
        mx=a[i];
        else if(a[i]<=mn)
        mn=a[i];
        else
        {
            f=false;
            break;
        }
    }
    if(f)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
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