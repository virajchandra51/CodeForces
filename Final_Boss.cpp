#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long h, n;
        cin >> h >> n;
        vector<long long> p(n);
        for (int i = 0; i < n; i++)
            cin >> p[i];
        vector<long long> c(n);
        for (int i = 0; i < n; i++)
            cin >> c[i];

        for (int i = 0; i < n; i++)
            h -= p[i];

        if (h <= 0)
        {
            cout << 1 << endl;
            continue;
        }

        long long l = 0;
        long long r = 1e18;
        long long ans;

        while (l <= r) // log2(1e18) = 60
        {
            long long mid = (l + r) >> 1;

            long long s = 0;

            for (int i = 0; i < n; i++) // O(n)
                s += (mid / c[i]) * p[i];

            if (h - s <= 0)
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }

        cout << ans + 1 << endl;
    }
    return 0;
}

// TC - O(n * log2(1e18))
// SC - O(n)

