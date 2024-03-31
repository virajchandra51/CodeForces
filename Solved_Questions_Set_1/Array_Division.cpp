#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fp(i, a, b) for (ll i = a; i < b; i++)
#define fn(i, a, b) for (ll i = a; i >= b; i--)
#define vec vector<ll>
#define mod (ll)(1e9 + 7) // Corrected calculation of the mod macro
#define pb push_back

bool ispos(vec v, ll mid, ll k)
{
    ll m = 1;
    ll s = 0;
    for (ll i = 0ll; i < (ll)v.size(); i++)
    {
        s += v[i];
        if (s > mid)
        {
            m++;
            s = v[i];
        }
    }
    return m <= k;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    vec v(n);
    ll sum = 0;
    ll mp = INT_MIN;
    fp(i, 0, n)
    {
        cin >> v[i];
        sum += v[i];
        mp = max(mp, v[i]);
    }
    ll low = mp;
    ll high = sum;
    ll ans = INT_MAX;
    while (high >= low)
    {
        ll mid = (low + high) / 2;
        if (ispos(v, mid, k))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}