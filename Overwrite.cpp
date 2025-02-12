// 2025-02-12 21:04:15

#include <bits/stdc++.h>

using namespace std;

// Speed
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

// Macros
#define IOtext                        \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define PI (3.141592653589)
#define M 1000000007
#define pb push_back
#define f first
#define s second
#define foreach(i, j, k, in) for (int i = j; i < k; i += in)
#define rforeach(i, j, k, in) for (int i = j; i >= k; i -= in)
#define rep(i, j) foreach (i, 0, j, 1)
#define rrep(i, j) rforeach(i, j, 0, 1)
#define set_bits(x) __builtin_popcountll(x)
#define zero_bits(x) __builtin_ctzll(x)
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define inint(x) \
    int x;       \
    cin >> x;
#define inll(x)      \
    long long int x; \
    cin >> x;
#define instr(x) \
    string x;    \
    cin >> x;
#define all(x) x.begin(), x.end()
#define out(x) cout << x << endl;
#define py cout << "YES" << endl
#define pn cout << "NO" << endl
#define pm cout << "-1" << endl
#define ps(x, y) fixed << setprecision(y) << x

// Typedef
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef map<char, int> mci;
typedef set<int> st;

// Debug Overloads
#ifdef khnhcodingkarlo
#define debug(x) \
    _print(x);   \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.f);
    cerr << ",";
    _print(p.s);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

// Operator Overloads
template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

// Sorting
bool sorta(const pair<int, int> &a, const pair<int, int> &b) { return (a.second < b.second); }
bool sortd(const pair<int, int> &a, const pair<int, int> &b) { return (a.second > b.second); }

// Bits
string decToBinary(int n)
{
    string s = "";
    int i = 0;
    while (n > 0)
    {
        s = to_string(n % 2) + s;
        n = n / 2;
        i++;
    }
    return s;
}
ll binaryToDecimal(string n)
{
    string num = n;
    ll dec_value = 0;
    int base = 1;
    int len = num.length();
    for (int i = len - 1; i >= 0; i--)
    {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    return dec_value;
}

// Check
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
bool isPerfectSquare(ll x)
{
    if (x >= 0)
    {
        ll sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}

// Constants
vector<ll> primes;
vector<bool> is_prime;

// Mathematical functions
void Sieve(int n)
{
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= n; i++)
        if (is_prime[i])
            for (ll j = i * i; j <= n; j += i)
                is_prime[j] = false;
}
void get_primes(int n)
{
    for (int i = 2; i <= n; i++)
        if (is_prime[i])
            primes.push_back(i);
}
ll mod_add(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
} //__gcd
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }
ll moduloMultiplication(ll a, ll b, ll mod)
{
    ll res = 0;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;
        b >>= 1;
    }
    return res;
}
ll powermod(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
// To find modulo inverse, call powermod(A,M-2,M)

struct RollingHash
{
    vl prefix, power;
    ll n;
    ll base;

    RollingHash(vl &arr, ll base_)
    {
        base = base_;
        n = arr.size();
        prefix.resize(n + 1, 0);
        power.resize(n + 1, 1);
        rep(i, n)
        {
            prefix[i + 1] = prefix[i] * base + (arr[i] + 100LL);
            power[i + 1] = power[i] * base;
        }
    }

    ll getHash(ll l, ll r) { return prefix[r] - prefix[l] * power[r - l]; }
};

int32_t main()
{
    fastio()
        // Rating? Neh. In love with experience.
        // Code Karlo, Coz KHNH :)
        auto solve = [&]()
    {
        ll n, m;
        cin >> n >> m;
        vl A(n), B(m);
        cin >> A >> B;

        ll startIdx = min_element(B.begin(), B.end()) - B.begin();
        rotate(B.begin(), B.begin() + startIdx, B.end());

        RollingHash hashA(A, 131LL), hashB(B, 131LL);
        vector<bool> op(n, false);
        ll lastOp = -1;

        auto commonPrefixLength = [&](ll start)
        {
            ll low = 0, high = m;
            while (low < high)
            {
                ll mid = (low + high + 1) / 2;
                if (start + mid <= n)
                {
                    ll hA = hashA.getHash(start, start + mid);
                    ll hL = hashB.getHash(0, mid);
                    if (hA == hL)
                        low = mid;
                    else
                        high = mid - 1;
                }
                else
                    high = mid - 1;
            }
            return low;
        };

        rep(i, n - m + 1)
        {
            if (lastOp != -1 && i <= lastOp + m - 1)
            {
                op[i] = true;
                lastOp = i;
            }
            else
            {
                if (A[i] > B[0])
                {
                    op[i] = true;
                    lastOp = i;
                }
                else if (A[i] == B[0])
                {
                    ll commonLen = commonPrefixLength(i);
                    if (commonLen < M && B[commonLen] < A[i + commonLen])
                    {
                        op[i] = true;
                        lastOp = i;
                    }
                }
            }
        }

        vector<ll> F(n);
        ll curOp = -1;
        rep(i, n)
        {
            if (i <= n - m && op[i])
                curOp = i;
            if (curOp != -1 && i <= curOp + m - 1)
                F[i] = B[i - curOp];
            else
                F[i] = A[i];
        }

        out(F);
    };

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}