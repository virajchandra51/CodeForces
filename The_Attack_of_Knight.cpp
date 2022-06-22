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
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    vector<pair<int,int>> v;
    if((x1-2)>=1)
    {
        if(y1-1>=1)
        v.push_back({x1-2,y1-1});
        if(y1+1<=8)
        v.push_back({x1-2,y1+1});
    }
    if((x1+2)<=8)
    {
        if(y1-1>=1)
        v.push_back({x1+2,y1-1});
        if(y1+1<=8)
        v.push_back({x1+2,y1+1});
    }
    if((y1-2)>=1)
    {
        if(x1-1>=1)
        v.push_back({x1-1,y1-2});
        if(x1+1<=8)
        v.push_back({x1+1,y1-2});
    }
    if((y1+2)<=8)
    {
        if(x1-1>=1)
        v.push_back({x1-1,y1+2});
        if(x1+1<=8)
        v.push_back({x1+1,y1+2});
    }
    
    if((x2-2)>=1)
    {
        if(y2-1>=1)
        v.push_back({x2-2,y2-1});
        if(y2+1<=8)
        v.push_back({x2-2,y2+1});
    }
    if((x2+2)<=8)
    {
        if(y2-1>=1)
        v.push_back({x2+2,y2-1});
        if(y2+1<=8)
        v.push_back({x2+2,y2+1});
    }
    if((y2-2)>=1)
    {
        if(x2-1>=1)
        v.push_back({x2-1,y2-2});
        if(x2+1<=8)
        v.push_back({x2+1,y2-2});
    }
    if((y2+2)<=8)
    {
        if(x2-1>=1)
        v.push_back({x2-1,y2+2});
        if(x2+1<=8)
        v.push_back({x2+1,y2+2});
    }
    

    set<pair<int,int>> s;
    int flag=0;
    for(auto it: v)
    {
        if(s.find(it)!=s.end())
        {
            flag=1;break;
        }
        s.insert(it);
    }
    if(flag)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
    
    
    
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