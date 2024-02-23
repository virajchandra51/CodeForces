#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<vector<int> > a(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            a[i][j] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 0;
            if (s[j] != '.')
                a[i][j] = 1;
        }
    } // n^2

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0)
                a[i][j] += a[i][j - 1];
            else if (j == 0)
                a[i][j] += a[i - 1][j];
            else
                a[i][j] += (a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1]);
        }
    } // n^2

    // for(auto it:a)
    // {
    //     for(auto i:it) cout<<i<<" ";
    //     cout<<endl;
    // }

    for (int i = 0; i < q; i++)
    {
        int y1, x1, y2, x2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        x2--;
        y1--;
        y2--;
        int countOfTrees = a[x2][y2];
        if (x1 - 1 >= 0)
        {
            countOfTrees -= a[x1 - 1][y2];
        }
        if (y1 - 1 >= 0)
        {
            countOfTrees -= a[x2][y1 - 1];
        }
        if (x1 - 1 >= 0 && y1 - 1 >= 0)
            countOfTrees += a[x1 - 1][y1 - 1];
        cout << countOfTrees << endl;
    } // q
    return 0;
}

// tc - O(n^2+q) ~ 10^5 - 10^6
// sc - O(n^2) or O(1)