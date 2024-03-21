#include <bits/stdc++.h>

using namespace std;

#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

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
    long long hashPrime = 1000000009; //m
    const long long base = 31; //p
    vector< long long > hashValues;
    vector< long long > powersOfBase;
    vector< long long > inversePowersOfBase;
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
            powersOfBase[j] = (base * powersOfBase[j - 1]) % hashPrime;
        }
        inversePowersOfBase[n] = mminvprime(powersOfBase[n], hashPrime);
        for (int j = n - 1; j >= 0; j--)
        {
            inversePowersOfBase[j] = mod_mul(inversePowersOfBase[j + 1], base, hashPrime);
        }
        hashValues.resize(n);
        for (int j = 0; j < n; j++)
        {
            hashValues[j] = ((s[j] - 'a' + 1LL) * powersOfBase[j]) % hashPrime;
            hashValues[j] = (hashValues[j] + (j > 0 ? hashValues[j - 1] : 0LL)) % hashPrime;
        }
    }
    long long substringHash(int l, int r) // O(1)
    {
        long long val1 = hashValues[r];
        long long val2 = l > 0 ? hashValues[l - 1] : 0LL;
        long long hash = ((val1 - val2 + hashPrime) * inversePowersOfBase[l]) % hashPrime;
        return hash;
    }
};

int main()
{
    fastio()
    string str;
    cin >> str;

    int n = str.size();

    struct Hashing h = Hashing(str); // O(n)

    for (int windowSize = 1; windowSize <= n; windowSize++) // O(n)
    {
        bool flag = true;
        int len = windowSize;
        for(int curindex = 0; curindex < n; curindex += len) // O(logn)
        {
            len = min(windowSize, n - curindex);
            flag &= h.substringHash(0, len - 1) == h.substringHash(curindex, curindex + len - 1); //O(1)
        }
        if (flag)
        {
            cout << windowSize << " ";
        }
    } // O(nlogn)
    return 0;
}

// tc - O(n+nlogn) - O(nlogn)
// sc - O(n)


