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
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end()); // nlogn
        long long c1 = 1;
        long long c2 = 1;
        for (int i = 1; i < n; i++) // n
            if (a[i] == a[0])
                c1++;
            else
                break;
        for (int i = n - 2; i >= 0; i--) // n
            if (a[i] == a[n - 1])
                c2++;
            else
                break;

        if (a[0] != a[n - 1])
            cout << c1 * c2 * 2 << endl;
        else
            cout << c1 * (c1 - 1) << endl;
    }
    return 0;
}

// tc - O(nlogn)
// sc - O(1)