#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> P(n + 1), pos(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> P[i];
            pos[P[i]] = i;
        }

        while (q--)
        {
            int l, r, k;
            cin >> l >> r >> k;
            int p = pos[k];

            if (p < l || p > r)
            {
                cout << -1 << " ";
                continue;
            }

            int needL = 0, needG = 0;
            int wrongL = 0, wrongG = 0;

            int a = l, b = r;
            while (true)
            {
                int m = (a + b) >> 1;
                if (m == p)
                    break;
                if (p < m)
                {
                    ++needG;
                    if (P[m] < k)
                        ++wrongG;
                    b = m - 1;
                }
                else
                {
                    ++needL;
                    if (P[m] > k)
                        ++wrongL;
                    a = m + 1;
                }
            }

            if (needL > k - 1 || needG > n - k)
            {
                cout << -1 << " ";
                continue;
            }

            int ans = 2 * max(wrongL, wrongG);
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}
