#include <bits/stdc++.h>
using namespace std;

struct cmp
{
    bool operator()(pair<char, int> a, pair<char, int> b)
    {
        return a.second > b.second;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    unordered_map<char, int> freq;
    for (char c : s)
    {
        freq[c]++;
    }
    vector<pair<char, int> > v;
    for (auto it : freq)
    {
        v.push_back(it);
    }

    sort(v.begin(), v.end(), cmp());

    long long ans = 0;
    for (int i = 0; i < v.size() && k > 0; i++)
    {
        int take = min(k, v[i].second);
        ans += (long long)take * take;
        k -= take;
    }
    cout << ans << endl;

    return 0;
}

// Time Complexity: O(n log n)
// Space Complexity: O(n)