#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int main()
{
    fastio() int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            if (i != 2)
                cout << i << ' ' << i << endl;
        cout << 2 << " " << 1 << endl;
        cout << endl;
    }
    return 0;
}

// tc - O(n)
// sc - O(1)
