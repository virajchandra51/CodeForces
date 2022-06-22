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
    string s;
    cin>>s;
    vi op;
    vi mp;
    rep(i,n)
    {
        if(s[i]=='(')
        op.push_back(i+1);
        else
        mp.push_back(i+1);
    }
    if(op.size()==0 || mp.size()==0)
    {
        cout<<n<<endl;
        return;
    }
    int p1 = 0, p2 = mp.size()-1;
    int c = 0;
    while(op[p1]<mp[p2] && p1<op.size() && p2>=0)
    {
        c++;
        p1++;
        p2--;
    }
    cout<<n-2*c<<endl;
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