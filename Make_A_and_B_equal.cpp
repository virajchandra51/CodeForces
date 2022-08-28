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
    ll suma=0;
    ll sumb=0;
    vi a(n),b(n);
    rep(i,n)
    {
        cin>>a[i];
        suma+=a[i];
    }
    rep(i,n)
    {
        cin>>b[i];
        sumb+=b[i];
    }
    if(suma!=sumb)
    cout<<-1<<endl;
    else
    {
        ll diff = 0;
        rep(i,n)
        diff+=(abs(a[i]-b[i]));
        cout<<diff/2<<endl;
    }
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