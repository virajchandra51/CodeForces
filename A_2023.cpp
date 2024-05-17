#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++)
            cin >> a[i];
        long long p = 1;
        for (long long i = 0; i < n; i++)
            p *= a[i];
        if (2023 % p != 0)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            cout << 2023 / p << " ";
            k--;
            for (int i = 1; i <= k; i++)
                cout << 1 << " ";
            cout << endl;
        }
    }
    return 0;
}

// tc - O(max(n,k))
// sc - O(n)
