// 2024-09-20 22:51:54

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

//PBDS
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

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

//Bits
string decToBinary(int n){string s="";int i = 0;while (n > 0) {s =to_string(n % 2)+s;n = n / 2;i++;}return s;}
ll binaryToDecimal(string n){string num = n;ll dec_value = 0;int base = 1;int len = num.length();for(int i = len - 1; i >= 0; i--){if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}

//Check
bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}

//Constants
vector <ll> primes;
vector <bool> is_prime;

// Mathematical functions
void Sieve(int n){ is_prime.assign(n + 1, true); is_prime[0] = is_prime[1] = false; for(ll i = 2; i * i <= n; i++) if(is_prime[i]) for(ll j = i * i; j <= n; j += i) is_prime[j] = false;}
void get_primes(int n){ for(int i = 2; i <= n; i++)  if(is_prime[i])  primes.push_back(i); }
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);} //__gcd 
ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}
ll moduloMultiplication(ll a,ll b,ll mod){ll res = 0;a %= mod;while (b){if (b & 1)res = (res + a) % mod;b >>= 1;}return res;}
ll powermod(ll x, ll y, ll p){ll res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}
//To find modulo inverse, call powermod(A,M-2,M)

int32_t main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    fastio()
    //Rating? Neh. In love with experience.
    //Code Karlo, Coz KHNH :)
    auto solve = [&] () {
        ll n;
        cin>>n;
        vector<ll> prm;
        for(auto it:primes)
        {
            if(it<=n)
            {
                prm.pb(it);
            }
            else
            {
                break;
            }
        }
        if(n<=4) return 0;
        else if(n<=6) return 2;
        else
        {
            int ans = 2;
            for(int i=3;i<prm.size();i++)
            {
                if(prm[i]-prm[i-1]==2)
                {
                    ans++;
                }
            }
            return ans;
        }
    };

    Sieve(10000000);
    get_primes(10000000);
    int t;
    cin>>t;
    rep(i,t)
    {
        cout<<"Case #"<<i+1<<": "<<solve()<<endl;
    }
    return 0;
}

// 185 182 2
// 1/4 in 2 days
// 1/16 in 4 days
// 1/64 in 6 days
// 1/128 in 8 days
// 1/1024 in 10 days

// 2/4 + 4/16 + 6/64 + 8/128 + 10/1024 ... 
//     + 2/16 + 4/64 + 6/128 + 8/1024 ...
// 2/4 + 2/16 + 2/64 + 2/128 + 2/1024 ...
// 2/4 + 2*(1/16)/(3/4)

// 1/2 in 1 day
// 1/8 in 3 days
// 1/32 in 5 days
// 1/128 in 7 days

// 1/2 + 3/8 + 5/32 + 7/128 ... 
//     + 1/8 + 3/32 + 5/128 ...
// 1/2 + 2/8 + 2/32 + 2/128 ...
// 1/2 + 2*

// 185 to 183
// range 185 to 187
// 

// 1/2 + 3/4 + 5/8 + 7/16 ..
//    + 1/4 + 3/8 + 5/16 ..
// 1/2 + 2/4 + 2/8 + 2/16 ..
// 1/2 + 2*(1/4/1/2) = 


// 185 to 184 in 2
// 1/2 in 1 day
// 1/8 in 3 days
// 1/16 in 5 days
// 1/32 in 5 days
// 1/128 in 7 days
// 1/64 in 7 days

// S   = 1/2 + 3/8 + 5/32 + 7/128 + 9/512 ...
// S/4 =     + 1/8 + 3/32 + 5/128 + 7/512 ...
// 3S/4 = 1/2 + 2/8 + 2/32 + 2/128 + 2/512 ...
// 3S/4 = 1/2 + 1/3 = 5/6
// S = 20/18 = 10/9

// S    = 5/16 + 7/64 + 9/256 + 11/1024 ...
// S/4  =      + 5/64 + 7/256 + 9/1024 ...
// 3S/4 = 5/16 + 2/64 + 2/256 + 2/1024 ...
// 3S/4 = 11/16
// S = 44/48 = 11/12




