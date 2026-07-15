#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> one, two, three;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
            one.push_back(i + 1);
        else if (x == 2)
            two.push_back(i + 1);
        else
            three.push_back(i + 1);
    }

    vector<vector<int> > ans;
    for (int i = 0; i < min(one.size(), min(two.size(), three.size())); i++)
        ans.push_back({one[i], two[i], three[i]});

    cout << ans.size() << endl;
    for (auto team : ans)
    {
        for (auto idx : team)
            cout << idx << " ";
        cout << endl;
    }

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)