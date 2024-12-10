#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) // n
        cin >> a[i];

    vector<int> dp;
    for (int i = 0; i < n; i++) // n
    {
        auto it = lower_bound(dp.begin(), dp.end(), a[i]); // logn
        if (it == dp.end())
            dp.push_back(a[i]);
        else
            *it = a[i];
    }
    cout << dp.size() << endl;
    return 0;
}

// tc - O(nlogn)
// sc - O(n)