// 200. Number of Islands - BFS

#include <bits/stdc++.h>

using namespace std;

bool isValid(int a, int b, int n, int m)
{
    if (a < 0 || b < 0 || a >= n || b >= m)
        return false;
    return true;
}

void BFS(vector<vector<char>> &grid, int sr, int sc, int n, int m, vector<vector<bool>> &visited)
{
    queue<pair<int, int>> Q;
    visited[sr][sc] = true;

    Q.push({sr, sc});

    while (!Q.empty())
    {
        int r = Q.front().first;
        int c = Q.front().second;

        Q.pop();

        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (isValid(r + i, c + j, n, m) && i != j && abs(i - j) <= 1)
                {
                    if (!visited[r + i][c + j] && grid[r + i][c + j] == '1')
                    {
                        visited[r + i][c + j] = true;
                        Q.push({r + i, c + j});
                    }
                }
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> V(n, vector<bool>(m, false));
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!V[i][j] && grid[i][j] == '1')
            {
                count++;
                BFS(grid, i, j, n, m, V);
            }
        }
    }

    return count;
}