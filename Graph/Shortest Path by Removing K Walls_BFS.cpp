#include <bits/stdc++.h>

using namespace std;

int solve(vector<vector<int>> &M, int k)
{

    int n = M.size();
    int m = M[0].size();

    vector<vector<int>> vis(n, vector<int>(m, -1));

    queue<vector<int>> Q;

    Q.push({k, 0, 0, 0});

    int ans = 0;

    int dRow[] = {-1, 0, 1, 0};
    int dCol[] = {0, 1, 0, -1};

    while (!Q.empty())
    {
        auto x = Q.front();
        Q.pop();

        int p = x[2];
        int q = x[3];

        int t = x[0];

        int dist = x[1];

        if (p == n - 1 && q == m - 1)
        {
            return dist;
        }

        if (M[p][q] == 1)
            t--; // when encounter 1 decrement k

        for (int i = 0; i < 4; i++)
        {

            int u = p + dRow[i];
            int v = q + dCol[i];

            if (u < 0 || u >= n || v < 0 || v >= m)
                continue;

            if (vis[u][v] < t) // it takes care of visit as well
            {
                vis[u][v] = t;

                Q.push({t, dist + 1, u, v});
            }
        }
    }

    return -1;
}

int BFS(vector<vector<int>> &grid, int k)
{
    vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), -1));
    queue<vector<int>> q;

    // queue stores (x,y,current path length,number of obstacles we can still remove)
    q.push({0, 0, 0, k});

    while (!q.empty())
    {
        auto t = q.front();
        int x = t[0], y = t[1];
        q.pop();

        // Exit if current position is outside of the grid
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size())
        {
            continue;
        }

        // Destination found
        if (x == grid.size() - 1 && y == grid[0].size() - 1)
            return t[2];
        // if we encounter an obstacle and can remove it
        if (grid[x][y] == 1)
        {
            if (t[3] > 0)
                t[3]--;
            else
                continue;
        }
        // The cell was previously visited by some path and we were able to remove more obstacles from the previous path.
        // Then we don't need to continue on our current path
        if (vis[x][y] != -1 && vis[x][y] >= t[3])
            continue;

        vis[x][y] = t[3];

        q.push({x + 1, y, t[2] + 1, t[3]});
        q.push({x, y + 1, t[2] + 1, t[3]});
        q.push({x - 1, y, t[2] + 1, t[3]});
        q.push({x, y - 1, t[2] + 1, t[3]});
    }
    return -1;
}
int solve(vector<vector<int>> &matrix, int k)
{
    return BFS(matrix, k);
}
