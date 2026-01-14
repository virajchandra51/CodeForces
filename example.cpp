int rows, cols;
int answer;
vector<vector<int> > grid;
vector<vector<bool> > visited;

void helper(int r, int c, int count)
{
    // If we reached the end
    if (grid[r][c] == 2)
    {
        if (count == 1)
        {
            answer++;
        }
        return;
    }

    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nc < 0 || nr >= rows || nc >= cols)
            continue;
        if (grid[nr][nc] == -1 || visited[nr][nc])
            continue;

        visited[nr][nc] = true;
        helper(nr, nc, count - 1);
        visited[nr][nc] = false; // backtrack
    }
}

int uniquePathsIII(vector<vector<int> > &g)
{
    grid = g;
    rows = grid.size();
    cols = grid[0].size();
    visited.assign(rows, vector<bool>(cols, false));

    int startR = 0, startC = 0;
    totalCells = 0;
    answer = 0;

    // Count cells & find start
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] != -1)
                totalCells++;
            if (grid[i][j] == 1)
            {
                startR = i;
                startC = j;
            }
        }
    }

    visited[startR][startC] = true;
    helper(startR, startC, totalCells);

    return answer;
}

// Time Complexity: O(4^(m*n)) in the worst case
// Space Complexity: O(m*n) for the visited array and recursion stack