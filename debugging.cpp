// 2024-06-26 00:57:23

#include <bits/stdc++.h>

using namespace std;

//Macros
#define PI (3.141592653589)
#define M 1000000007
#define pb push_back
#define f first
#define s second
#define foreach(i, j, k, in) for(int i=j;i<k;i+=in)
#define rforeach(i, j, k, in) for(int i=j;i>=k;i-=in)
#define rep(i,j) foreach(i,0,j,1)
#define rrep(i,j) rforeach(i,j,0,1)
#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl
#define pm cout<<"-1"<<endl
#define ps(x,y) fixed<<setprecision(y)<<x

//Typedef
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef map<char,int> mci;
typedef set<int> st;

// Debug Overloads
// if khnhcodingkarlo is defined
#ifdef khnhcodingkarlo
#define debug(x) _print(x); cerr << endl;
#else
#define debug(x)
#endif

// 5 basic data types, function overloading, polymorphism
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

// Mix of interface + function overloading
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.f); cerr << ","; _print(p.s); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

int main()
{
    int w;
    cin>>w;
    pair<int,int> p ={4,5};
    set<int> s;
    map<int,int> m;
    m[1]=2;
    m[2]=3;
    m[3]=4;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    debug(p);
    debug(s);
    debug(m);
    if(w%2==1 || w==2)
    {
        debug("Printed a No");
        cout<<"NO"<<endl;
    }
    else
    {
        debug("Printed a Yes");
        cout<<"YES"<<endl;
    }
    return 0;
}

// local machine

// overloading 

// cerr
// cout

// VScode
// Sublime
// Clion