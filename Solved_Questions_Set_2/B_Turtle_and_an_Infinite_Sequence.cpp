#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long n, m;
        cin >> n >> m;

        long long L = max(0LL, n - m);
        long long R = n + m;
        long long ans = 0;

        for (int i = 0; i <= 60; i++)
        {
            long long bit = 1LL << i;
            // Case 1: L already has the bit
            if (L & bit)
                ans |= bit;
            // Case 2: R already has the bit
            else if (R & bit)
                ans |= bit;
            // Case 3: range crosses a block boundary
            else if ((L >> (i + 1)) != (R >> (i + 1)))
                ans |= bit;
        }
        cout << ans << "\n";
    }
    return 0;
}

// Time Complexity: O(60) per test case
// Space Complexity: O(1)