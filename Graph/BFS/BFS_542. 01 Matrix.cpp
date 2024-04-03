#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>> &M)
{
    int n = M.size();
    int m = M[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    queue<pair<int, int>> Q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] == 0)
            {
                Q.push({i, j});
                vis[i][j] = 1;
            }
        }
    }

    vector<int> dir = {0, 1, 0, -1, 0};

    int level = 0;

    while (!Q.empty())
    {
        int z = Q.size();

        while (z--)
        {
            auto [u, v] = Q.front();
            Q.pop();

            M[u][v] = level;

            for (int k = 0; k < 4; k++)
            {
                int i = u + dir[k];
                int j = v + dir[k + 1];

                if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j])
                    continue;

                else
                {
                    vis[i][j] = 1;
                    Q.push({i, j});
                }
            }
        }

        level++;
    }

    return M;
}