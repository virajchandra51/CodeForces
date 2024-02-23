#include <bits/stdc++.h>
using namespace std;

// globals

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool findCycle = false;

void dfs(int n, int m, int x, int y, int fromX, int fromY, vector<string> &board, 
char needColor, vector<vector<int> > &visited)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return;
    if (board[x][y] != needColor)
        return;
    if (visited[x][y])
    {
        findCycle = true;
        return;
    }

    visited[x][y] = true;
    for (int f = 0; f < 4; f++)
    {
        int nextX = x + dx[f];
        int nextY = y + dy[f];
        if (nextX == fromX && nextY == fromY)
            continue;
        dfs(n, m, nextX, nextY, x, y, board, needColor, visited);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> board(n);
    for (int i = 0; i < n; i++)
        cin >> board[i];
    // taking input

    vector<vector<int> > vis(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!vis[i][j])
                dfs(n, m, i, j, -1, -1, board, board[i][j], vis);

    cout << (findCycle ? "Yes" : "No") << endl;
    return 0;
}

// tc - O(n*m) 2500 ~ 10^3
// sc - O(n*m)
