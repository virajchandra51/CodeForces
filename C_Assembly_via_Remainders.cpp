#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int main()
{
    fastio() int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n - 1);
        for (int i = 0; i < n - 1; i++)
            cin >> a[i];
        vector<long long> ans;
        ans.push_back(a[n - 2]);
        ans.push_back(1e9);
        for (int i = n - 3; i >= 0; i--)
        {
            ans.push_back(ans.back() - a[i]);
        }
        reverse(ans.begin(), ans.end());
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}

// tc - O(n)
// sc - O(n)