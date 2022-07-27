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
    int x,y,z;
    cin>>x>>y>>z;
    int a[] = {x,y,z};
    sort(a,a+3);
    x=a[0];
    y=a[1];
    z=a[2];
    if(x!=y && y!=z)
    cout<<"NO"<<endl;
    else if((x==y && y>z) || (x==z && z>y) || (y==z && y>x))
    cout<<"NO"<<endl;
    else
    cout<<"YES"<<endl;
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