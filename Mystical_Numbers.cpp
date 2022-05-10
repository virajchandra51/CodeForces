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
    int dp[33][n+1];
    for(int i=0;i<33;i++)
    {
        for(int j=0;j<n;j++)
        {
            if( (a[j]^((ll)pow(2,i))) > (a[j]&((ll)pow(2,i))) )
            dp[i][j]=1;
            else
            dp[i][j]=0;
        }
    }
    rep(i,33)
    {
        for(int j=1;j<n;j++)
        {
            dp[i][j]+=dp[i][j-1];
        }
        cout<<endl;
    }
    
    int q;
    cin>>q;
    while(q--)
    {
        int si,ei,x;
        cin>>si >> ei>>x;
        int p = (log2(x));
        if(si==1)
        cout<<dp[p][ei-1]<<endl;
        else
        cout<<dp[p][ei-1]-dp[p][si-1]<<endl;
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