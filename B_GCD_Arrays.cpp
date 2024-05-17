#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long l, r, k;
        cin >> l >> r >> k;
        if (l == 1 && r == 1)
            cout << "NO" << endl;
        else if (l == r)
            cout << "YES" << endl;
        else
        {
            long long op = (r - l + 1) / 2;
            if (l % 2 == 1 && r % 2 == 1)
                op++;
            if (op <= k)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}

// tc - O(1)
// sc - O(1)
