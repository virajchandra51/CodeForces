#include <bits/stdc++.h>

using namespace std;

bool comparator(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int> > a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].second;
            a[i].first = i + 1;
        }

        for (int i = 0; i < n; i++)
        {
            a[i].second = a[i].second % k;
            if (a[i].second <= 0)
            {
                a[i].second += k;
            }
        }

        sort(a.begin(), a.end(), comparator); // nlogn
        // dec in second, inc in first

        for (int i = 0; i < n; i++)
        {
            cout << a[i].first << " ";
        }
        cout << endl;
    }
    return 0;
}

// Time Complexity: O(nlogn)
// Space Complexity: O(n)