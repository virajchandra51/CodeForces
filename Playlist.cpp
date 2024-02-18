#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    map<int, int> m;
    int start = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (m.find(a[i]) != m.end())
            start = max(start, m[a[i]] + 1);
        m[a[i]] = i;
        ans = max(ans, i - start + 1);
    }
    cout << ans << endl;
    return 0;
}