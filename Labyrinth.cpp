#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char> > v(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            v[i][j] = s[j];
    }
    // taking input

    int sx = -1;
    int sy = -1;
    int dx = -1;
    int dy = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'A')
            {
                sx = i;
                sy = j;
            }
            if (v[i][j] == 'B')
            {
                dx = i;
                dy = j;
            }
        }
    }

    queue<pair<int, int> > q;
    q.push({sx, sy});
    vector<vector<int> > vis(n, vector<int>(m, 0));
    vector<vector<int> > previousStep(n, vector<int>(m));

    vis[sx][sy] = 1;
    int dirx[] = {0, 0, -1, 1};
    int diry[] = {-1, 1, 0, 0};
    char dir[] = {'L', 'R', 'U', 'D'};
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int x = node.first + dirx[k];
            int y = node.second + diry[k];
            if (x >= 0 && x < n && y >= 0 && y < m && v[x][y] != '#' && !vis[x][y])
            {
                vis[x][y] = 1;
                q.push({x, y});
                previousStep[x][y] = k;
            }
        }
    }
    if (vis[dx][dy] == 1)
    {
        cout << "YES" << endl;
        string directionString = "";
        while (dx != sx || dy != sy)
        {
            int p = previousStep[dx][dy];
            directionString += dir[p];
            dx -= dirx[p];
            dy -= diry[p];
        }
        reverse(directionString.begin(), directionString.end());
        cout << directionString.size() << endl;
        cout << directionString << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}

// TC - O(n)
// SC - O(n)