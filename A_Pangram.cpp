#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;

    unordered_map<char, int> freq;
    for (auto c : s)
    {
        if (c >= 'a' && c <= 'z')
            freq[c]++;
        else
            freq[c + 32]++;
    }

    if (freq.size() == 26)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)