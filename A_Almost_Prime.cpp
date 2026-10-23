#include <bits/stdc++.h>
using namespace std;

int cnt[3001];

int main()
{
    int n;
    cin >> n;

    for (int p = 2; p <= n; p++)
        if (cnt[p] == 0)
            for (int j = p; j <= n; j += p)
                cnt[j]++;

    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (cnt[i] == 2)
            ans++;

    cout << ans << '\n';
}

// Time Complexity: O(n ln ln n)
// Space Complexity: O(n)