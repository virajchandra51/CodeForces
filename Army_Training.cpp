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
    ll sa=0,sd=0;
    rep(i,n)
    {
        cin>>a[i];
        sa+=a[i];
    }
    sort(a,a+n);
    sa-=a[0];
    sd+=(1000-a[0]);
    ll m=sa*sd;
    for(int i=1;i<n;i++)
    {   
        sa-=a[i];
        sd+=(1000-a[i]);
        if(sa*sd>m)
        m=sa*sd;
    }
    cout<<m<<endl;
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