#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, x;
        cin >> n >> x;
        vector<long long> a(n);
        long long min = 0, max = 0;
        // ceil is an STL function
        // that return greater integer
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            max += ceil(a[i] * 1.0 / x * 1.0);
            // long long / long long = long long
            min += a[i];
        }
        min = ceil(min * 1.0 / x * 1.0);
        cout << min << " " << max << endl;
    }
    return 0;
}

// TC - O(n)
// SC - O(n)