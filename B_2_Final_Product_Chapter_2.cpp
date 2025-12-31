// 2025-10-18 22:31:31

#include <bits/stdc++.h>

using namespace std;

//Speed
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

//Macros
#define IOtext freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
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
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define inint(x) int x; cin>>x;
#define inll(x) long long int x; cin>>x;
#define instr(x) string x; cin>>x;
#define all(x) x.begin(), x.end()
#define out(x) cout << x << endl;
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
#ifdef khnhcodingkarlo
#define debug(x) _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.f); cerr << ","; _print(p.s); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

// Operator Overloads
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

//Sorting
bool sorta(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
bool sortd(const pair<int,int> &a,const pair<int,int> &b){return (a.second > b.second);}

ll powermod(ll a, ll b, ll mod) {
    ll res = 1; a %= mod;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a) { return powermod(a, M - 2, M); }

ll nCr_small(ll n, ll r) {
    if (r < 0 || n < r) return 0;
    if (r == 0 || n == r) return 1;
    ll res = 1;
    for (ll i = 1; i <= r; i++) {
        ll num = (n - i + 1) % M;
        if (num < 0) num += M;
        res = res * num % M;
        res = res * modinv(i) % M;
    }
    return res;
}

vector<pair<ll,ll>> factorize(ll x) {
    vector<pair<ll,ll>> f;
    for (ll p = 2; p * p <= x; p++) {
        if (x % p == 0) {
            ll e = 0;
            while (x % p == 0) x /= p, e++;
            f.pb({p, e});
        }
    }
    if (x > 1) f.pb({x, 1});
    return f;
}

void genDivisors(int idx, ll curr, const vector<pair<ll,ll>>& f, vector<ll>& divs) {
    if (idx == (int)f.size()) { divs.pb(curr); return; }
    ll p = f[idx].f, val = 1;
    for (int i = 0; i <= f[idx].s; i++) {
        genDivisors(idx + 1, curr * val, f, divs);
        val *= p;
    }
}

ll ways(ll N, ll X) {
    auto f = factorize(X);
    ll res = 1;
    for (int i = 0; i < (int)f.size(); i++) {
        ll e = f[i].s;
        res = res * nCr_small(e + N - 1, e) % M;
    }
    return res;
}

int32_t main() {
    fastio()
    //Rating? Neh. In love with experience.
    //Code Karlo, Coz KHNH :)
    auto solve = [&] () {
        ll N, A, B;
        cin >> N >> A >> B;
        auto fB = factorize(B);
        vector<ll> divs;
        genDivisors(0, 1, fB, divs);
    
        ll ans = 0;
        for (auto d : divs) {
            if (d <= A) {
                ans = (ans + ways(N, d) * ways(N, B / d) % M) % M;
            }
        }
        out(ans);
    };
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
