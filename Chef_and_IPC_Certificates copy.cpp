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
    int n,m,k;
    cin >> n >> m >> k;
    int count=0;
    while(n--){  
        int a[k+1];
        int sum=0;
        for (int i=0; i<(k+1); i++)
        {
            cin >> a[i];
        }
        for (int i=0; i<k; i++)
        {
            sum += a[i];
        }
        if (sum>=m && a[k]<=10)
        {
            count++;
        }
    }
    cout << count << endl;    
}


int32_t main()
{
    fastio()
    int t=1;
    //cin>>t;
    while(t--)
    {
    answertoProb();
    }
    return 0;
}