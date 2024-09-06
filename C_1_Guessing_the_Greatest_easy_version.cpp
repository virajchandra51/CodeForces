#include <bits/stdc++.h>
using namespace std;

#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define int long long

// int ask(int l, int r)
// {
//     cout << "? " << l << " " << r << endl;
//     int x;
//     cin >> x;
//     return x;
// }

int ask(int l, int r, vector<int> a)
{
    cout << "l: " << l << " r: " << r << endl;
    int x = 0;
    for (int i = l - 1; i <= r - 1; i++)
    {
        x = max(x, a[i]);
    }
    int y = 0;
    for (int i = l - 1; i <= r - 1; i++)
    {
        if (a[i] == x)
        {
            continue;
        }
        else
        {
            y = max(y, a[i]);
        }
    }
    int ind = -1;
    for (int i = l - 1; i <= r - 1; i++)
    {
        if (a[i] == y)
        {
            ind = i;
            break;
        }
    }
    return ind + 1;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l = 1, r = n;
    int ans;
    while (l < r)
    {
        int m = (l + r) / 2;
        int x = ask(l, r, a);
        cout << "m: " << m << endl;
        cout << "x: " << x << endl;
        if (x <= m)
        {
            int y = ask(l, m, a);
            cout << "y: in x<=m " << y << endl;
            if (y == x)
            {
                ans = y;
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        else
        {
            int y = ask(m + 1, r, a);
            cout<< "y: in x>m " << y << endl;
            if (y == x)
            {
                ans = y;
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
    }
    // cout << "! " << ans + 1 << endl;
    cout << ans + 1 << endl;
}

int32_t main()
{
    fast_io;
    solve();
    return 0;
}