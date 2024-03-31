#include <bits/stdc++.h>

#define pi (3.141592653589)
#define M 1000000007
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define ioset ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define ps(x, y) fixed << setprecision(y) << x
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define vvl vector<vl>

using namespace std;

int check(ll mid, vector<ll> &v, ll m)
{
    ll cnt = 1, prv = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if ((v[i] - prv) >= mid)
        {
            cnt++;
            prv = v[i];
        }
    }
    if (cnt >= m)
        return 1;
    return 0;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    ll lo = 0, hi = 1e18;
    while (lo + 1 < hi)
    {
        ll mid = lo + ((hi - lo) / 2);
        if (check(mid, v, m))
        {
            lo = mid;
        }
        else
            hi = mid;
    }
    cout << lo << endl;
}

int32_t main()
{
    ioset int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}