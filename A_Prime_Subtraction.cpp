#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x, y;
        cin >> x >> y;
        long long diff = x - y;
        if (diff > 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

// Time Complexity: O(1)
// Space Complexity: O(1)