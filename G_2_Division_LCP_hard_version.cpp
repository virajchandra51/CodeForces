#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<pair<ll, ll> > vpll;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;

#define SZ 1000005

pll p = {31, 53};
pll inv_p = {129032259, 56603774};
pll inv_p_1 = {233333335, 788461544};

ll mod = 1e9 + 7;

vpll hash_array1;
vpll hash_array2;
ll powerval[SZ];

void calcpow()
{
    powerval[0] = 1;
    for (int i = 1; i < SZ; i++)
    {
        powerval[i] = (p.first * powerval[i - 1]) % mod;
    }
}

vl calchash(string &s)
{
    int n = s.length();
    vl hash_array(n);
    for (int i = 0; i < n; i++)
        hash_array[i] = 0;
    hash_array[0] = (s[0] - 'a' + 1);
    for (int i = 1; i < n; i++)
    {
        hash_array[i] = ((p.first * hash_array[i - 1]) + (s[i] - 'a' + 1)) % mod;
    }
    return hash_array;
}

ll hashval(ll l, ll r, vl &hash_array)
{
    ll len = r - l + 1;
    int n = hash_array.size();
    if (len <= 0 || l < 0 || r >= n || r < l)
        return 0;
    ll ans = hash_array[r];
    if (l >= 1)
    {
        ans -= (hash_array[l - 1] * powerval[len]) % mod;
    }
    if (ans < 0)
        ans += mod;
    return ans;
}

vl hv;
ll n, l, r;

map<ll, ll> store;

ll check(ll x)
{
    if (store.count(x))
        return store[x];
    ll ans = 0;
    ll temp = hashval(0, x - 1, hv);

    for (int i = 0; i < n; i++)
    {
        int j = i + x - 1;
        if (j >= n)
            break;

        ll cur = hashval(i, j, hv);

        if (cur == temp)
        {
            i += x - 1;
            ans++;
        }
    }
    return store[x] = ans;
}

int main()
{
    int t;
    cin >> t;
    calcpow();
    while (t--)
    {
        cin >> n >> l >> r;
        string str;
        cin >> str;
        store.clear();
        hv.clear();
        hv = calchash(str);
        ll pre = n;
        for (ll x = l; x <= r; x++)
        {
            ll low = 1;
            ll high = pre;
            ll ans = 0;
            while (low <= high)
            {
                ll mid = (low + high) / 2;
                if (check(mid) >= x)
                {
                    ans = mid;
                    low = mid + 1;
                }
                else
                    high = mid - 1;
            } // O(nlogn)
            cout << ans << " ";
            pre = ans;
        }
        cout << endl;
    }
    return 0;
}

// tc - O(nlogn)
// sc - O(n)
