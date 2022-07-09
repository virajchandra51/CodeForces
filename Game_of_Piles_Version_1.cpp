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
    int f=0;
    rep(i,n)
    {
        if(a[i]==1)
        f=1;
    }
    if(f)
    cout<<"CHEF"<<endl;
    else
    {
        ll sum=0;
        rep(i,n)
        sum+=(a[i]-2);
        if(!(sum&1))
        cout<<"CHEFINA"<<endl;
        else
        cout<<"CHEF"<<endl;
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