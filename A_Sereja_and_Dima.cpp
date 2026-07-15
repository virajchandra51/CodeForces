#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(a[i]);

    int sereja_score = 0;
    int dima_score = 0;
    int turn = 0; // 0 for Sereja, 1 for Dima

    while (!s.empty())
    {
        int max_element = *s.rbegin();
        s.erase(max_element);
        if (turn == 0)
            sereja_score += max_element;
        else
            dima_score += max_element;
        turn = 1 - turn; // Switch turns
    }

    cout << sereja_score << " " << dima_score << "\n";

    return 0;
}

// Time Complexity: O(n * logn)
// Space Complexity: O(n)