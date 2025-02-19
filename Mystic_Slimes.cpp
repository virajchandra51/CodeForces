#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (long long &x : a) // n
            cin >> x;

        long long ans = 0;
        for (int i = 0; i < n; i++) // n
        {
            long long left;
            long long right;
            if (i != 1)
                left = 0;
            else
                left = a[0];

            if (i != n - 2)
                right = 0;
            else
                right = a[n - 1];

            ans = max(ans, a[i] - (left + right));
        }
        cout << ans << endl;
    }
    return 0;
}

// tc = O(N) = O(50)
// sc = O(N) = O(50)