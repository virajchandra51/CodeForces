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
        freq[c]++;

    if (freq['A'] > freq['D'])
        cout << "Anton\n";
    else if (freq['A'] < freq['D'])
        cout << "Danik\n";
    else
        cout << "Friendship\n";

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)