#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long s, n;
    cin >> s >> n;
    vector<pair<long, long> > v;
    for (long i = 0; i < n; i++)
    {
        long x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    sort(v.begin(), v.end());
    for (long i = 0; i < n; i++)
    {
        if (s > v[i].first)
        {
            s += v[i].second;
        }
        else
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

    return 0;
}

// Time Complexity: O(n log n) due to sorting the vector of pairs.
// Space Complexity: O(n) for storing the vector of pairs.