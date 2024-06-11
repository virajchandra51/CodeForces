#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        vector<vector<char> > a(n, vector<char>(m));
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++)
                a[i][j] = s[j];
        }

        long long firstRow = -1, lastRow = -1;
        long long firstCol = -1, lastCol = -1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == '#')
                {
                    if (firstRow == -1)
                    {
                        firstRow = i;
                        break;
                    }
                }
            }
            if (firstRow != -1)
                break;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == '#')
                {
                    if (lastRow == -1)
                    {
                        lastRow = i;
                        break;
                    }
                }
            }
            if (lastRow != -1)
                break;
        }

        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i][j] == '#')
                {
                    if (firstCol == -1)
                    {
                        firstCol = j;
                        break;
                    }
                }
            }
            if (firstCol != -1)
                break;
        }

        for (int j = m - 1; j >= 0; j--)
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i][j] == '#')
                {
                    if (lastCol == -1)
                    {
                        lastCol = j;
                        break;
                    }
                }
            }
            if (lastCol != -1)
                break;
        }

        firstRow++;
        lastRow++;
        firstCol++;
        lastCol++;

        cout << (firstRow + (lastRow - firstRow) / 2) << " " << (firstCol + (lastCol - firstCol) / 2) << endl;
    }
    return 0;
}

// TC - O(n*m)
// SC - O(n*m)