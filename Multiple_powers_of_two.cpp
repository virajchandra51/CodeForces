#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    long long maxi = 32;
    while (q--)
    {
        long long x;
        cin >> x;
        if (x >= maxi)
            continue;
        maxi = x;
        for (int i = 0; i < n; i++)
        {
            if ((a[i] & ((1 << x) - 1)) == 0)
                a[i] += ((1 << x) - 1);
        }
    }
    //  31 * n
    for (auto it : a)
        cout << it << " ";
    cout << endl;
    return 0;
}

// tc - O(31*n)
// sc - O(n)