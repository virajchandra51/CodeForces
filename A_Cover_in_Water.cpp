#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int total_count_of_empty = 0; // total number of empty cells
    int current_count_of_empty = 0; // number of empty cells in a continuous segment

    // auto - auto keyword is used to automatically deduce the data type of the variable.
    for (int i = 0; i < n; i++)  
    {
        if (s[i] == '.')
            current_count_of_empty++;
        else
        {
            total_count_of_empty += current_count_of_empty;
            if (current_count_of_empty >= 3)
            {
                cout << 2 << endl;
                return;
            }
            current_count_of_empty = 0;
        }
    }

    total_count_of_empty += current_count_of_empty;
    
    cout << total_count_of_empty << endl;
}

// tc - O(n)
// sc - O(1)

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