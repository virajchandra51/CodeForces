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
    
    if(n > 26)
    {
        cout << -1 << "\n";
        return 0;
    }

    unordered_set<char> unique_characters;
    for (char c : s)
        unique_characters.insert(c);
        
    int characters_to_change = n - unique_characters.size();
    cout << characters_to_change << "\n";

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)