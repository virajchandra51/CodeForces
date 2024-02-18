#include <bits/stdc++.h>
using namespace std;

static bool comp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int> > v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end(), comp); // O(nlogn)

    int maxMovies = 0;
    multiset<int> end_times;
    for (int i = 0; i < k; i++) 
        end_times.insert(-1); // O(klogk)

    for (int i = 0; i < n; i++) // O(n)
    {
        auto it = end_times.upper_bound(v[i].first); // O(logk)
        if (it == begin(end_times))
            continue;
        // assign movie to be watched by member in multiset who finishes at time
        // *prev(it)
        end_times.erase(--it); // O(logk)
        // member now finishes watching at time v[i].second
        end_times.insert(v[i].second); //O(logk)
        ++maxMovies;
    } //O(nlogk)
    cout << maxMovies << endl;
    return 0;
}

// TC - O(nlogn + klogk + nlogk) ~ 10^6
// SC - O(k)