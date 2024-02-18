#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long tc;
    cin >> tc;
    while (tc--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n, 0);
        for (long long i = 0; i < n; i++)
            cin >> a[i];

        long long maxSecondsRequired = 0;
        for (long long i = 1; i < n; i++)
        {
            if (a[i] < a[i - 1])
            {
                long long diff = a[i - 1] - a[i];
                long long highestSetBitPosition = (long long)(log2(diff));
                maxSecondsRequired = max(highestSetBitPosition, maxSecondsRequired);
                a[i] = a[i - 1];
            }
        }
        if (maxSecondsRequired != 0)
            cout << maxSecondsRequired + 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}

// tc - O(n)
// sc - O(1)