#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fp(i, a, b) for (ll i = a; i < b; i++)
#define fn(i, a, b) for (ll i = a; i >= b; i--)
#define vec vector<ll>

#define pb push_back
#define int long long

bool isprime(int x) {
    if (x <= 1)
        return false;
    if (x == 2 || x == 3)
        return true;
    if (x % 2 == 0 || x % 3 == 0)
        return false;
    if ((x - 1) % 6 != 0 && (x + 1) % 6 != 0)
        return false;
    for (int i = 5; i * i <= x; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0)
            return false;
    }
    return true;
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int solve() {
    int n, k;
    cin >> n >> k;
    vec v(2 * n);
    fp(i, 0, 2 * n)
        cin >> v[i];
    vector<vector<ll>> index(n + 1, vector<ll>());
    vec l, r, mid;

    fp(i, 0, 2 * n) {
        index[v[i]].pb(i);
    }

    fp(i, 1, n + 1) {
        if (index[i][0] <= n - 1 && index[i][1] <= n - 1) {
            l.pb(i);
        } else if (index[i][0] > n - 1 && index[i][1] > n - 1) {
            r.pb(i);
        } else
            mid.pb(i);
    }

    int ls = l.size();
    int rs = r.size();
    int mids = mid.size();
    int cur = 0;
    vec a1, a2;
    while (ls > 0 && rs > 0 && cur < k) {
        a1.pb(l[--ls]);
        a1.pb(l[ls]); 
        a2.pb(r[--rs]);
        a2.pb(r[rs]); 
        cur++;
    }
    int x = 0;
    while (cur < k) {
        a1.pb(mid[x]);
        a2.pb(mid[x++]);
        cur++;
    }
    fp(i, 0, k)
        cout << a1[i] << " ";
    cout << endl;

    fp(i, 0, k)
        cout << a2[i] << " ";
    cout << endl;

    return 0;
}

signed main() {
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}