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

int32_t main()
{
    fastio()
    vi a;
    a.push_back(1);
    a.push_back(1);
    for(int i=2;i<=1000002;i++)
    {
        a.push_back((a[i-1]*2)%1000000007);
    }
    int t;
    cin>>t;
    while(t--)
    {
        ll n,x;
        cin>>n>>x;
        cout<<(x*a[n])%1000000007<<endl;
    }
    return 0;
}