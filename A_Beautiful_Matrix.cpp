#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<int> > v(5, vector<int>(5));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> v[i][j];
        }
    }

    int x, y;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (v[i][j] == 1)
            {
                x = i;
                y = j;
                break;
            }
        }
    }

    cout << abs(x - 2) + abs(y - 2) << "\n";

    return 0;
}

// Time Compexity: O(1)
// Space Complexity: O(1)