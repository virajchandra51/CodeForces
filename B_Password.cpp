#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define sz(x) ((int)(x).size())

typedef long long ll;

ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m

struct Hashing
{
    string s;
    int n;
    int primes;
    long long hashPrimes = 1000000009;
    const long long base = 31;
    vector<long long> hashValues;
    vector<long long> powersOfBase;
    vector<long long> inversePowersOfBase;
    Hashing(string a)
    {
        hashValues.resize(primes);
        powersOfBase.resize(primes);
        inversePowersOfBase.resize(primes);
        s = a;
        n = s.length();
        powersOfBase.resize(n + 1);
        inversePowersOfBase.resize(n + 1);
        powersOfBase[0] = 1;
        for (int j = 1; j <= n; j++)
        {
            powersOfBase[j] = (base * powersOfBase[j - 1]) % hashPrimes;
        }
        inversePowersOfBase[n] = mminvprime(powersOfBase[n], hashPrimes);
        for (int j = n - 1; j >= 0; j--)
        {
            inversePowersOfBase[j] = mod_mul(inversePowersOfBase[j + 1], base, hashPrimes);
        }
        hashValues.resize(n);
        for (int j = 0; j < n; j++)
        {
            hashValues[j] = ((s[j] - 'a' + 1LL) * powersOfBase[j]) % hashPrimes;
            hashValues[j] = (hashValues[j] + (j > 0 ? hashValues[j - 1] : 0LL)) % hashPrimes;
        }
    }
    long long substringHash(int l, int r) // O(1)
    {
        long long hash;
        long long val1 = hashValues[r];
        long long val2 = l > 0 ? hashValues[l - 1] : 0LL;
        hash = ((val1 - val2 + hashPrimes) % hashPrimes * inversePowersOfBase[l]) % hashPrimes;
        return hash;
    }
};

int main()
{
    string str;
    cin >> str;

    int n = str.size();

    struct Hashing h = Hashing(str); // O(n)

    vector<long long> lengths;

    for (long long i = 0; i < n - 1; i++) // O(n)
    {
        if (h.substringHash(0, i) == h.substringHash(n - i - 1, n - 1)) // O(1)
            lengths.push_back(i + 1);
    }

    if (lengths.size() == 0)
    {
        cout << "Just a legend" << endl;
        return 0;
    }

    int low = 0;
    int high = lengths.size() - 1;
    int ans = -1;

    while (low <= high) // O(logn)
    {
        int mid = (low + high) >> 1;
        int psLength = lengths[mid];
        bool check = false;
        long long hashValueOfPrefix = h.substringHash(0, psLength - 1);
        for (int i = 1; i <= n - psLength - 1; i++) // O(n)
        {
            if (h.substringHash(i, i + psLength - 1) == hashValueOfPrefix)
                check = true;
        }
        if (check)
        {
            ans = psLength;
            low = mid + 1;
        }
        else
            high = mid - 1;
    } 
    if (ans == -1)
        cout << "Just a legend" << endl;
    else
        cout << str.substr(0, ans) << endl;
}

// tc - O(n+n+nlogn) - O(nlogn)
// sc - O(n)