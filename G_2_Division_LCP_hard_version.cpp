#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(string s)
{
    int n = s.size(), l = 0, r = 0;
    vector<int> z(n);
    for (int i = 1; i < n; i++)
    {
        if (i < r)
            z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] > r)
            l = i, r = i + z[i];
    }
    z[0] = n;
    return z;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;

        string str;
        cin >> str;

        vector<int> z = z_function(str);
        vector<int> mx(n + 1, 0), ans(n + 1, 0);
        set<int> st;
        vector<vector<int> > indices(n + 1);
        for (int i = 0; i < n; i++)
            indices[z[i]].push_back(i);

        for (int len = n; len >= 1; len--)
        {
            for (auto idx : indices[len])
                st.insert(idx);
            int i = 0;
            while (true)
            {
                auto next = st.lower_bound(i);
                if (next == st.end())
                    break;
                i = *next + len;
                mx[len]++;
            }
        }

        int k = 1;
        for (int len = n; len >= 1; len--)
        {
            while (k <= n && mx[len] >= k)
            {
                ans[k++] = len;
            }
        }

        for (int k = l; k <= r; k++)
            cout << ans[k] << " \n"[k == r];
    }

    return 0;
}