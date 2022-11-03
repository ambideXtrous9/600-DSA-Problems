#include <bits/stdc++.h>

using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>> &M)
{
    int n = M.size();

    queue<pair<int, int>> Q;

    Q.push({0, 0});

    if (M[0][0] || M[n - 1][n - 1])
        return -1;

    M[0][0] = 1;

    int level = 1;

    while (!Q.empty())
    {

        int z = Q.size();

        while (z--)
        {

            auto [u, v] = Q.front();
            Q.pop();

            if (u == n - 1 && v == n - 1)
                return level;

            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    if (i == 0 && j == 0)
                        continue;

                    int x = u + i;
                    int y = v + j;

                    if (x < 0 || y < 0 || x >= n || y >= n || M[x][y] == 1)
                        continue;

                    if (x == n - 1 && y == n - 1)
                        return level + 1;

                    M[x][y] = 1;
                    Q.push({x, y});
                }
            }
        }

        level++;
    }

    return -1;
}