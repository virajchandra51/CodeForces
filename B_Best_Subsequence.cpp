#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) // n
        cin >> a[i];

    vector<pair<long long, long long> > b(n);
    for (int i = 0; i < n; i++) // n
        b[i] = {a[i], i};

    sort(b.begin(), b.end()); // nlogn

    vector<long long> mark(n, 0);
    for (int i = 0; i < k; i++) // k
        mark[b[i].second] = 1;

    vector<long long> ans;
    for (int i = 0; i < n; i++) // n
    {
        if (mark[i])
            ans.push_back(a[i]);
    }

    long long s = INT_MIN;
    for (int i = 0; i < k; i++) // k
        s = max(s, ans[i] + ans[(i + 1) % k]);

    cout << s << endl;

    return 0;
}