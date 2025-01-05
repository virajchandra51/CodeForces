#include <bits/stdc++.h>
#define endl "\n"
#define FAST_IO              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define mod 1000000007
#define int long long
using namespace std;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{

    int n, a, b;
    cin >> n >> a >> b;

    vector<int> v(n);

    for (auto &x : v)
        cin >> x;

    vector<int> psum(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        psum[i] = psum[i - 1] + v[i - 1];
    }

    deque<int> dq;

    int ans = LLONG_MIN;

    for (int i = a; i <= n; i++)
    {

        while (!dq.empty() && dq.back() < psum[i])
            dq.pop_back();
        dq.push_back(psum[i]);

        if (i - a >= b)
        {
            if (dq.front() == psum[i - a])
                dq.pop_front();
        }

        if (i >= b)
            ans = max(ans, dq.front() - psum[i - b]);
    }

    cout << ans << endl;
}

signed main()
{

    auto begin = std::chrono::high_resolution_clock::now();

    FAST_IO;
    // int t; cin >> t; while(t--)
    solve();

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}