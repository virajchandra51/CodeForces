#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int maximum_length_of_new_string = 0, n = s.size();
    bool prev[26] = {false};
    for (int i = 0; i < n; i++)
    {
        if (prev[s[i] - 'a'] == true)
        {
            maximum_length_of_new_string += 2;
            for (int j = 0; j < 26; j++) // resetting the prev array
                prev[j] = false;
        }
        else
            prev[s[i] - 'a'] = true;
    }

    cout << n - maximum_length_of_new_string << endl;
}

// tc - O(n)
// sc - O(26)

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}