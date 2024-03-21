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
    vector<long long> hashPrimes = {1000000009, 1000000007};
    const long long base = 67;
    vector<vector<long long> > hashValues;
    vector<vector<long long> > powersOfBase;
    vector<vector<long long> > inversePowersOfBase;
    Hashing(string a)
    {
        primes = sz(hashPrimes);
        hashValues.resize(primes);
        powersOfBase.resize(primes);
        inversePowersOfBase.resize(primes);
        s = a;
        n = s.length();
        for (int i = 0; i < sz(hashPrimes); i++)
        {
            powersOfBase[i].resize(n + 1);
            inversePowersOfBase[i].resize(n + 1);
            powersOfBase[i][0] = 1;
            for (int j = 1; j <= n; j++)
            {
                powersOfBase[i][j] = (base * powersOfBase[i][j - 1]) % hashPrimes[i];
            }
            inversePowersOfBase[i][n] = mminvprime(powersOfBase[i][n], hashPrimes[i]);
            for (int j = n - 1; j >= 0; j--)
            {
                inversePowersOfBase[i][j] = mod_mul(inversePowersOfBase[i][j + 1], base, hashPrimes[i]);
            }
        }
        for (int i = 0; i < sz(hashPrimes); i++)
        {
            hashValues[i].resize(n);
            for (int j = 0; j < n; j++)
            {
                hashValues[i][j] = ((s[j] - 'a' + 1LL) * powersOfBase[i][j]) % hashPrimes[i];
                hashValues[i][j] = (hashValues[i][j] + (j > 0 ? hashValues[i][j - 1] : 0LL)) % hashPrimes[i];
            }
        }
    }
    vector<long long> substringHash(int l, int r) // O(1)
    {
        vector<long long> hash(primes);
        for (int i = 0; i < primes; i++)
        {
            long long val1 = hashValues[i][r];
            long long val2 = l > 0 ? hashValues[i][l - 1] : 0LL;
            hash[i] = mod_mul(mod_sub(val1, val2, hashPrimes[i]), inversePowersOfBase[i][l], hashPrimes[i]);
        }
        return hash;
    }
};

int main()
{
    string str, bad;
    cin >> str >> bad;

    int k;
    cin >> k;

    int n = str.size();

    struct Hashing h = Hashing(str); // O(n)

    vector<long long> prefixBad(n + 1, 0);

    for (int i = 1; i <= n; i++) // O(n)
    {
        if (bad[str[i - 1] - 'a'] == '0')
            prefixBad[i] = prefixBad[i - 1] + 1;
        else
            prefixBad[i] = prefixBad[i - 1];
    }

    // for(auto it:prefixBad) cout<<it<<" "; cout<<endl;

    vector<vector<long long> > hashes;

    for (long long i = 0; i < n; i++) // O(n)
    {
        for (long long window = 1; window <= (n - i); window++) // O(n)
        {
            int l = i;
            int r = i + window - 1;
            vector<long long> hashValue = h.substringHash(l, r); // O(1)
            l++;
            r++;
            int badOnes = prefixBad[r] - prefixBad[l - 1];
            if (badOnes <= k)
                hashes.push_back(hashValue); // O(1)
        }
    } // O(n^2)

    // 1500 * 1500 = 2250000 ~ 2*10^6

    // o - number of substrings that i get

    sort(hashes.begin(), hashes.end()); // ologn 
    int uniqueHash = 0;
    for (int i = 1; i < hashes.size(); i++) //o
    {
        if (hashes[i] != hashes[i - 1])
            uniqueHash++;
    }
    if (hashes.size() == 0)
        cout << 0 << endl;
    else
        cout << uniqueHash + 1 << endl;

}


// tc - (n+n+n^2+ologo+o) ~ 10^6
// sc - (n+o)