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
    ll sum=0;
    vi a(n);
    rep(i,n)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sort(a.begin(),a.end());
    if(sum/n == a[n-1])
    cout<<0<<endl;
    else
    {
        int ans=n-2;
        while(true)
        {
            int avg = sum/(ans+1);
            if(avg>=a[ans])
            {
                cout<<n-1-ans<<endl;
                break;
            }
            else
            ans--;
        }
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