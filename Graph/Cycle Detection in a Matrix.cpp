#include <bits/stdc++.h>

using namespace std;

const vector<int> dirs{0, 1, 0, -1, 0};

bool dfs(const vector<vector<int>> &grid, int i, int j, int prevI, int prevJ, int c, vector<vector<bool>> &seen)
{
    seen[i][j] = true;

    for (int k = 0; k < 4; ++k)
    {
        const int x = i + dirs[k];
        const int y = j + dirs[k + 1];

        if (x < 0 || x == grid.size() || y < 0 || y == grid[0].size())
            continue;

        if (x == prevI && y == prevJ)
            continue;

        if (grid[x][y] != c)
            continue;

        if (seen[x][y])
            return true;

        if (dfs(grid, x, y, i, j, c, seen))
            return true;
    }

    return false;
}
bool solve(vector<vector<int>> &grid)
{
    const int m = grid.size();
    const int n = grid[0].size();

    vector<vector<bool>> seen(m, vector<bool>(n,false));

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (seen[i][j])
                continue;

            if (dfs(grid, i, j, -1, -1, grid[i][j], seen))
                return true;
        }
    }

    return false;
}