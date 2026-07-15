#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int)(x).size())
typedef long long ll;

ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}

struct Hashing
{
    string s;
    int n;
    int primes;
    vector<long long> hashPrimes = {1000000009, 100000007}; // double hashing to avoid collisions
    const long long base = 31; // number of unique characters
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
            powersOfBase[i].resize(n + 1); // Precompute powers of base modulo hashPrimes[i]
            inversePowersOfBase[i].resize(n + 1); // Precompute inverse powers of base modulo hashPrimes[i]
            powersOfBase[i][0] = 1; // powersOfBase[i][0] = base^0 = 1
            
            for (int j = 1; j <= n; j++)
            {
                powersOfBase[i][j] = (base * powersOfBase[i][j - 1]) % hashPrimes[i];
            }
            inversePowersOfBase[i][n] = mminvprime(powersOfBase[i][n], hashPrimes[i]);
            for (int j = n - 1; j >= 0; j--)
            {
                inversePowersOfBase[i][j] = (inversePowersOfBase[i][j + 1] * base) % hashPrimes[i];
            }
        }

        for (int i = 0; i < sz(hashPrimes); i++)
        {
            hashValues[i].resize(n); // Precompute hash values for the string s modulo hashPrimes[i]
            for (int j = 0; j < n; j++)
            {
                hashValues[i][j] = ((s[j] - 'a' + 1LL) * powersOfBase[i][j]) % hashPrimes[i];
                hashValues[i][j] = (hashValues[i][j] + (j > 0 ? hashValues[i][j - 1] : 0LL)) % hashPrimes[i];
            }
        }
    }

    // Time Complexity: O(N) overall for precomputation

    vector<long long> substringHash(int l, int r)
    {
        vector<long long> hash(primes);
        for (int i = 0; i < primes; i++)
        {
            long long val1 = hashValues[i][r];
            long long val2 = l > 0 ? hashValues[i][l - 1] : 0LL;
            hash[i] = ((val1 - val2 + hashPrimes[i]) % hashPrimes[i] * inversePowersOfBase[i][l]) % hashPrimes[i];
        }
        return hash;
    }

    // Time Complexity: O(1) for each substring hash query
};