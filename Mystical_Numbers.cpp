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
    int dp[n+1][33];
    for(int i=1;i<=n;i++)
    {
        int temp = a[i-1];
        for(int j=0;j<33;j++)
        {
            dp[i][j]=dp[i-1][j];
        }
        int pwr=32;
        if(temp!=0) pwr = (int)(log(temp)/log(2));
        dp[i][pwr]++;
    }
    int q;
    cin>>q;
    while(q--)
    {
        int si,ei,x;
        cin>> si >> ei>>x;
        int scnt=0;
        int pwr=32;
        if(x!=0) pwr=(int)(log(x)/log(2));
        scnt = dp[ei][pwr]-dp[si-1][pwr];
        int ans = ei-si+1-scnt;
        cout<<ans<<endl;

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