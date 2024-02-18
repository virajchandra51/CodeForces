#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    set<int> m;
    int violations = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        m.insert(v[i]);
        int count = m.lower_bound(v[i])-m.begin();
        violations += count;
    }
    cout << violations << endl;

    return 0;
}
// tc - O(n) - O(100)
// sc - O(1)