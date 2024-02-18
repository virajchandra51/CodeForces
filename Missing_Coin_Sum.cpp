#include <bits/stdc++.h>
using namespace std;

int main()
{
    long n;
    cin >> n;
    vector<long> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    long ans = 1;
    for (auto x : v)
    {
        if (x > ans)
            break;
        ans += x;
    }
    cout << ans << endl;
    return 0;
}
