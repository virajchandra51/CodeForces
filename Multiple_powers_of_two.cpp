#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long minimum_processed_so_far = 32;
    while (q--)
    {
        long long x;
        cin >> x;
        if (x >= minimum_processed_so_far)
            continue;
        minimum_processed_so_far = x;
        for (int i = 0; i < n; i++)
        {
            if ((a[i] & ((1 << x) - 1)) == 0)
                a[i] += ((1 << x) - 1);
        }
    } // 31 * n

    for (auto it : a)
        cout << it << " ";
    cout << endl;
    return 0;
}

// Time Complexity = O(n * 31) = O(n)
// Space Complexity = O(n)