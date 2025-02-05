#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> a;
        int empty = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '.')
                empty++;
            else
                a.push_back(empty);
        }
        for (auto it : a)
            cout << it << " ";
        cout << endl;
        int mid = (a.size() - 1) / 2;
        long long ans = 0;
        for (auto x : a)
        {
            ans += abs(x - a[mid]);
        }
        cout << ans << endl;
    }
    return 0;
}