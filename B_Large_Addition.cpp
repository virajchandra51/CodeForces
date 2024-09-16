#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long x;
    cin >> x;
    int flag = 1;

    while (x >= 10)
    {
        int digit = x % 10;
        if (flag == 1)
        {
            flag = 0;
            if (digit > 8)
            {
                cout << "NO" << endl;
                return;
            }
        }
        else if (digit == 0)
        {
            cout << "NO" << endl;
            return;
        }
        x /= 10;
    }

    if (x == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

// tc - O(log10(x)) - 18
// sc - O(1)

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}