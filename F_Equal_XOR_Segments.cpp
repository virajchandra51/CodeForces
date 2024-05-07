#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int main()
{
    fastio() int t;
    cin >> t;
    while (t--)
    {
        long long n, q;
        cin >> n >> q;
        vector<long long> a(n + 1), pfx(n + 1);
        map<long long, vector<long long> > mp;

        mp[0].push_back(0);

        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            pfx[i] = pfx[i - 1] ^ a[i];
            mp[pfx[i]].push_back(i);
        } // nlogn
        for (int i = 0; i < q; i++) // O(q)
        {
            long long l, r;
            cin >> l >> r;
            long long x = (pfx[r] ^ pfx[l - 1]);
            if (x == 0)
            {
                cout << "YES" << endl;
                continue;
            }
            auto &v1 = mp[pfx[r]], &v2 = mp[pfx[l - 1]];
            auto it1 = lower_bound(v1.begin(), v1.end(), l); // logn
            auto it2 = --lower_bound(v2.begin(), v2.end(), r); // logn
            if (*it1 < *it2)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        cout << endl;
    }
    return 0;
}

// tc - O(nlogn+qlogn)
