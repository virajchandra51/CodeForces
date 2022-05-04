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
    int n,x;
    cin>>n>>x;
    int a[n]; int sum=0;
    rep(i,n)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int ans1=a[n-1];
    rep(i,n)
    {
        a[i]=ceil((a[i]*1.0)/x);
        sum+=a[i];
    }
    cout<<min(sum,ans1)<<endl;
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