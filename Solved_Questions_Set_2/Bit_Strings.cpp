#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int M = 1e9 + 7;
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ((ans % M) * (2 % M)) % M;
    }
    cout << ans << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)