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
    int n,x,y,a,b;
    cin >> n >> x >> y >> a >> b;
    if((n*1.0/b)*y>(n*1.0/a)*x)
    cout<<"PETROL"<<endl;
    else if((n*1.0/b)*y<(n*1.0/a)*x)
    cout<<"DIESEL"<<endl;
    else
    cout<<"ANY"<<endl;
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