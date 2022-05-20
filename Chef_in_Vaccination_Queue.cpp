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
    int n,p,x,y;
    cin >> n >> p >> x >> y;
    int a[n];
    int count0=0, count1=0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i]; 
    }
    for (int i = 0; i < p; i++)
    {
        if (a[i]==0)
        {
            count0++; 
        }
        else
        {
            count1++; 
        }
    }
    
    cout<<(count0*x) + (count1*y) << endl;
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