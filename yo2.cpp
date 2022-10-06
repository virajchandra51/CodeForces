/** author: kicker
*   created: 05-10-2022 20:38
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long                           ll;
#define line                                << "\n"
#define sep                                 << " " <<
#define sp                                  << " "
#define loop(i, x, n)                       for (ll i = x; i < n; i++)
#define rep(i, x, n)                        for (int i = x; i < n; i++)
#define rrep(i, x, n)                       for (ll i = x; i >= n; i--)
#define f                                   first
#define s                                   second
#define all(x)                              x.begin(), x.end()
#define dsort(x)                            sort(all(x), greater<ll>())
#define vi                                  vector<int>
#define vs                                  vector<string>
#define vll                                 vector<long long>
#define pb                                  push_back
#define pf                                  push_front
#define vc                                  vector<char>
#define sll                                 set<ll>
#define mll                                 map<ll, ll>
#define pqMax                               priority_queue<ll>
#define pqMin                               priority_queue<int, vector<ll>, greater<ll>>

template <typename T> bool _equal(T a[], ll n) { return std::all_of(a, a+n, [a](T x){ return x==a[0]; }); }
template <typename T> T aMax(T a[], T n) { T mx = a[0]; loop(i, 0, n) mx = max(mx, a[i]); return mx; }
template <typename T> T aMin(T a[], T n) { T mn = a[0]; loop(i, 0, n) mn = min(mn, a[i]); return mn; }
template <typename T> void parr(T a[], ll n) { loop(i, 0, n) cout << a[i] << " "; cout line; }
template <typename T> void print(vector<T> v) { loop(i, 0, v.size()) cout << v[i] << " "; cout line; }

ll kadane(ll a[], ll s, ll e)
{
    ll max_so_far = INT_MIN, max_ending_here = 0;
 
    for (ll i = s; i <= e; i++) {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

void solve() {
    ll n;
    cin >> n;
    ll a[n];
    loop(i, 0, n) cin >> a[i];

    ll m;
    cin >> m;
    ll b[m];
    loop(i, 0, m) cin >> b[i];

    ll fs = 0, ls = 0, end = 0, fneg = 0, lneg = 0;
    loop(i, 0, n) {
        end += a[i];
        if (end < 0) {
            fneg = i;
            break;
        }
        if (end > fs) {
            fs = end;
        }
    }

    end = 0;
    rrep(i, n - 1, 0) {
        end += a[i];
        if (end < 0) {
            lneg = i;
            break;
        }
        if (end > ls) {
            ls = end;
        }
    }

    ll ans = max(fs, ls);
    cout<<ans<<endl;
    loop (i, 0, m) {
        if (b[i] > 0) ans += b[i];
    }
    ans = max(ans, kadane(a, fneg, lneg));
    cout << ans line;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    #endif

    ll t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}