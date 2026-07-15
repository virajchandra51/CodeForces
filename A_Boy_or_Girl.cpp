#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    unordered_set<char> unique_characters;

    for (auto c : s)
        unique_characters.insert(c);
    
    if (unique_characters.size() % 2 == 1)
        cout << "IGNORE HIM!\n";
    else
        cout << "CHAT WITH HER!\n";
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)