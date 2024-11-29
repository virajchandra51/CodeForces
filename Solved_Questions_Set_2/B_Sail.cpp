// 2022-07-01 02:22:24
// Viraj Chandra
// Linkedin: https://www.linkedin.com/in/viraj-chandra-4073a8223/
// Codeforces: https://codeforces.com/profile/khnhcodingkarlo
// Codechef: https://www.codechef.com/users/codecozkhnhs

#include <bits/stdc++.h>
using namespace std;

//Speed
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

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
#define set_bits(x) __builtin_popcountll(x)
#define zero_bits(x) __builtin_ctzll(x)
#define inint(x) int x; cin>>x;
#define inll(x) long long int x; cin>>x;
#define instr(x) string x; cin>>x;
#define all(x) x.begin(), x.end()
#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl
#define pm cout<<"-1"<<endl
#define ps(x,y) fixed<<setprecision(y)<<x

//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int,int> mii;
typedef set<int> st;

#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" ";_print(x); cerr<<endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

// Operator overloads
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

//Sorting
bool sorta(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
bool sortd(const pair<int,int> &a,const pair<int,int> &b){return (a.second > b.second);}

//Bits
string decToBinary(int n){string s="";int i = 0;while (n > 0) {s =to_string(n % 2)+s;n = n / 2;i++;}return s;}
ll binaryToDecimal(string n){string num = n;ll dec_value = 0;int base = 1;int len = num.length();for(int i = len - 1; i >= 0; i--){if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}

//Check
bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}

// Mathematical functions
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);} //__gcd 
ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}
ll moduloMultiplication(ll a,ll b,ll mod){ll res = 0;a %= mod;while (b){if (b & 1)res = (res + a) % mod;b >>= 1;}return res;}
ll powermod(ll x, ll y, ll p){ll res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}

void solve()
{
    int t,x1,y1,x2,y2;
    cin >>t>>x1>>y1>>x2>>y2;
    string s;
    cin>>s;
    map<char,vi> mp;
    rep(i,t)
    mp[s[i]].push_back(i+1);
    if(x1==x2 && y1!=y2)
    {
        if(y1-y2>0)
        {
            int diff = y1-y2;
            int si = mp['S'].size();
            if(si<diff)
            {
                pm;
            }
            else
            {
                cout<<mp['S'][diff-1]<<endl;
            }
        }
        else
        {
            int diff = y2-y1;
            int si = mp['N'].size();
            if(si<diff)
            {
                pm;
            }
            else
            {
                cout<<mp['N'][diff-1]<<endl;
            }
        }
    }
    else if(x1!=x2 && y1==y2)
    {
        if(x1-x2>0)
        {
            int diff = x1-x2;
            int si = mp['W'].size();
            if(si<diff)
            {
                pm;
            }
            else
            {
                cout<<mp['W'][diff-1]<<endl;
            }
        }
        else
        {
            int diff = x2-x1;
            int si = mp['E'].size();
            if(si<diff)
            {
                pm;
            }
            else
            {
                cout<<mp['E'][diff-1]<<endl;
            }
        }
    }
    else
    {
        if(x2-x1>0 && y2-y1>0)
        {
            int diff1 = x2-x1;
            int diff2 = y2-y1;
            int si1 = mp['E'].size();
            int si2 = mp['N'].size();
            if(si1<diff1 || si2<diff2)
            {
                pm;
            }
            else
            {
                cout<<max(mp['E'][diff1-1],mp['N'][diff2-1])<<endl;
            }
        }
        if(x2-x1>0 && y1-y2>0)
        {
            int diff1 = x2-x1;
            int diff2 = y1-y2;
            int si1 = mp['E'].size();
            int si2 = mp['S'].size();
            if(si1<diff1 || si2<diff2)
            {
                pm;
            }
            else
            {
                cout<<max(mp['E'][diff1-1],mp['S'][diff2-1])<<endl;
            }
        }
        if(x1-x2>0 && y2-y1>0)
        {
            int diff1 = x1-x2;
            int diff2 = y2-y1;
            int si1 = mp['W'].size();
            int si2 = mp['N'].size();
            if(si1<diff1 || si2<diff2)
            {
                pm;
            }
            else
            {
                cout<<max(mp['W'][diff1-1],mp['N'][diff2-1])<<endl;
            }
        }
        if(x1-x2>0 && y1-y2>0)
        {
            int diff1 = x1-x2;
            int diff2 = y1-y2;
            int si1 = mp['W'].size();
            int si2 = mp['S'].size();
            if(si1<diff1 || si2<diff2)
            {
                pm;
            }
            else
            {
                cout<<max(mp['W'][diff1-1],mp['S'][diff2-1])<<endl;
            }
        }
    }
}


int32_t main()
{
    fastio()
    #ifndef ONLINE_JUDGE
        freopen("Error.txt","w",stderr);
    #endif
    //Rating? Neh. In love with experience.
    //Code Karlo, Coz KHNH :)
    int t;
    t=1;
    while(t--)
    {
    solve();
    }
    return 0;
}