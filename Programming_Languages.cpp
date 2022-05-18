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
    int a,b,a1,b1,a2,b2;
    cin >> a >> b >> a1 >> b1 >> a2 >> b2;
    if ((a==a1 || a==b1) && (b==a1 || b==b1))
    {
        cout << 1 << endl;
    }
    else if ((a==a2 || a==b2) && (b==a2 || b==b2))
    {
        cout << 2 << endl;
    }
    else cout << 0 << endl;
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