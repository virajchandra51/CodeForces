// 2024-04-23 00:55:06
// Viraj Chandra
// Linkedin: https://www.linkedin.com/in/viraj-chandra-4073a8223/
// Codeforces: https://codeforces.com/profile/khnhcodingkarlo
// Codechef: https://www.codechef.com/users/codecozkhnhs

#include <bits/stdc++.h>

using namespace std;


//Speed
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);


int n, ans;

set<pair<int, int>> infect, vaccinated;
vector<pair<int, int>> safe;

void util(int ind, int krem) {
    if (!krem) {
        bool grid[2][n];
        memset(grid, 0, sizeof(grid));
        queue<pair<int, int>> q;
        for (auto x : infect) {
            q.push(x);
            grid[x.first][x.second] = 1;
        }
        while (!q.empty()) {
            int ix = q.front().first, iy = q.front().second;
            q.pop();
            if (ix - 1 >= 0 && !grid[ix - 1][iy] && vaccinated.find({ix - 1, iy}) == vaccinated.end()) {
                grid[ix - 1][iy] = 1;
                q.push({ix - 1, iy});
            }
            if (iy - 1 >= 0 && !grid[ix][iy - 1] && vaccinated.find({ix, iy - 1}) == vaccinated.end()) {
                grid[ix][iy - 1] = 1;
                q.push({ix, iy - 1});
            }
            if (ix + 1 < 2 && !grid[ix + 1][iy] && vaccinated.find({ix + 1, iy}) == vaccinated.end()) {
                grid[ix + 1][iy] = 1;
                q.push({ix + 1, iy});
            }
            if (iy + 1 < n && !grid[ix][iy + 1] && vaccinated.find({ix, iy + 1}) == vaccinated.end()) {
                grid[ix][iy + 1] = 1;
                q.push({ix, iy + 1});
            }
        }
        int curr = 0;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++)
                curr += (!grid[i][j]);
        ans = max(ans, curr);
        return;
    }
    if (ind == safe.size())
        return;
    vaccinated.insert(safe[ind]);
    util(ind + 1, krem - 1);
    vaccinated.erase(safe[ind]);
    util(ind + 1, krem);
}

int32_t main()
{
    fastio()
    //Rating? Neh. In love with experience.
    //Code Karlo, Coz KHNH :)
    auto solve = [&] () {
        int m, k;
        cin >> n >> m >> k;    
        while (m--) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            infect.insert({x, y});
        }
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++)
                if (infect.find({i, j}) == infect.end())
                    safe.push_back({i, j});
        util(0, k);
        cout << ans;
    };

    int t;
    t=1;
    while(t--)
    {
        solve();
    }
    return 0;
}