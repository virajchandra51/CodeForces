#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    for (char c : s)
    {
        if (c == 'H' || c == 'Q' || c == '9')
        {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)