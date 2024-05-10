// Radhe Radhe
// Author :  AryRDW
// Date   :  10-05-2024
// Time   :  21:10:49
#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long             ll;
typedef long double           ld;
typedef pair<int,int>         pii;
typedef pair<ll,ll>           pll;
typedef pair<double,double>   pdd;
typedef vector<ll>            vl;
typedef vector<pll>           vpl;
typedef vector<pii>           vpi;
typedef vector<int>           vi;
typedef vector<vector<int>>   vvi;
typedef vector<vector<ll>>    vvl;
#define lb                    lower_bound;
#define ub                    upper_bound;
#define yeah                  cout<<"Yes"<<endl
#define nope                  cout<<"No"<<endl
#define forn(i,e)             for(ll i = 0; i < e; i++)
#define forsn(i,s,e)          for(ll i = s; i < e; i++)
#define rforn(i,s)            for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e)         for(ll i = s; i >= e; i--)
#define ln                    "\n"
#define mp                    make_pair
#define pb                    push_back
#define fi                    first
#define se                    second
#define INF                   2e18
#define all(x)                (x).begin(), (x).end()
#define sz(x)                 (ll)(x).size()

#ifndef ONLINE_JUDGE  
#define dbg(x)                cerr<<#x<<"  ";_print(x);cerr<<endl;
#else
#define dbg(x);
#endif
#ifndef ONLINE_JUDGE  
#define dbg2(x,n);            cerr<<#x<<" ";_print(x,n);cerr<<endl;
#else
#define dbg2(x,n);
#endif
template<class T,class V> void _print(pair<T,V> p);
template<class T>void _print(set<T> v);
template<class T>void _print(multiset<T> v) ;
template<class T,class V>void _print(map<T, V> v);
template<class T>void _print(vector<T> v);
void _print(int t) {cerr << t;}
void _print(ll t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;} 
template<class T,class V> void _print(pair<T,V> p) {cerr<<"{"; _print(p.first);cerr<<","; _print(p.second);cerr<<"}";}
template<class T>void _print(vector<T> v) {cerr<<" [ "; for (T i:v){_print(i);cerr<<" ";}cerr<<"]";}
template<class T>void _print(vector<T> v,int n) {cerr<<" [ "; int j=0; for (T i:v){ if(j>=n)break;j++; _print(i);cerr<<" ";}cerr<<"]";}
template<class T>void _print(set<T> v) {cerr<<" [ "; for (T i:v){_print(i); cerr<<" ";}cerr<<"]";}
template<class T>void _print(multiset<T> v) {cerr<< " [ "; for (T i:v){_print(i);cerr<<" ";}cerr<<"]";}
template<class T,class V>void _print(map<T, V> v) {cerr<<" [ "; for(auto i:v) {_print(i);cerr<<" ";} cerr<<"]";} 
template<class T,class V>void _print(unordered_map<T, V> v) {cerr<<" [ "; for(auto i:v) {_print(i);cerr<<" ";} cerr<<"]";}
template<class T,class V>void _print(queue<T, V> v) {cerr<<" [ "; while(!v.empty()) {_print(v.front());cerr<<" ";v.pop();} cerr<<"]";}
template<class T,class V>void _print(stack<T, V> v) {cerr<<" [ "; while(!v.empty()) {_print(v.top());cerr<<" ";v.pop();} cerr<<"]";}
template<class T,class V>void _print(priority_queue<T, V> v) {cerr<<" [ "; while(!v.empty()) {_print(v.front());cerr<<" ";v.pop();} cerr<<"]";}

template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll binpow(ll a, ll b, ll MOD) {
    a %= MOD;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll modInverse(ll a, ll M)
{
    ll m0 = M;
    ll y = 0, x = 1;
    if (M == 1)return 0;
    while(a>1) {
        ll q = a/ M;
        ll t = M;M = a % M, a= t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)x += m0;
    return x;
}

ll gcd(ll a, ll b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}
ll lcm (ll a, ll b) {
    return a / gcd(a, b) * b;
}

void ord_erase(ordered_set<int> &s, int v){
    auto rank = s.order_of_key(v);
    auto it = s.find_by_order(rank);
    s.erase(it);
}
void ord_erase(ordered_multiset<int> &s, int v){
    auto rank = s.order_of_key(v);
    auto it = s.find_by_order(rank);
    s.erase(it);
}


ll MOD = 998244353;
//const ll N=1e5+5;
//ll dp[N];
struct SCC {
    int N;
    vector<vector<int>> adj, radj;
    vector<int> todo, comp, comps;
    vector<bool> vis;
    void init(int _N) {
        N = _N;
        adj.resize(N), radj.resize(N), comp = vector<int>(N, -1), vis.resize(N);
    }
    void ae(int x, int y) { adj[x].push_back(y), radj[y].push_back(x); }
    void dfs(int x) {
        vis[x] = 1;
        for (int y : adj[x])
            if (!vis[y]) dfs(y);
        todo.push_back(x);
    }
    void dfs2(int x, int v) {
        comp[x] = v;
        for (int y : radj[x])
            if (comp[y] == -1) dfs2(y, v);
    }
    void gen() {  // fills allComp
        for (int i = 0; i < N; i++)
            if (!vis[i]) dfs(i);
        reverse(begin(todo), end(todo));
        for (int x : todo)
            if (comp[x] == -1) { dfs2(x, x), comps.push_back(x); }
    }
};
void solve()
{
    ll n;
    cin>>n;
    vvl vec(3,vl(n,0));
    forn(i,3){
        forn(j,n){
            cin>>vec[i][j];
        }
    }
    SCC graph;
    graph.init(2*n+1);
    forn(i,n){
        forn(j,3){
            forn(k,3){
                if(k!=j){
                    ll u=vec[j][i];
                    ll v=vec[k][i];
                    if(u>0)u=abs(u)+n;
                    else{
                        u=abs(u);
                    }
                    if(v<0)v=abs(v)+n;
                    // dbg(mp(u,v));
                    graph.ae(u,v);
                }
            }
        }
    }
    for(int i=0;i<graph.adj.size();i++)
    {
        cout<<i<<endl;
        for(auto j:graph.adj[i])
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    graph.gen();
    auto tmp=graph.comp;
    forsn(i,1,n+1){
        if(tmp[i]==tmp[i+n]){
            nope;return;
        }
    }
    yeah;
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cout<<fixed<<setprecision(0);
    ll t=1;
    cin >> t;
    forn(i,t)
    {
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}