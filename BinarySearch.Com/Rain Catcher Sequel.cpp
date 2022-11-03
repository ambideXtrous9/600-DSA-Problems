#include <bits/stdc++.h>

using namespace std;

typedef pair<int, pair<int, int>> PI;

int solve(vector<vector<int>> &M)
{

    int n = M.size();
    int m = M[0].size();

    // use min-heap and store all boundary walls height then go for BFS

    priority_queue<PI, vector<PI>, greater<PI>> H;

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j])
            {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
                {
                    H.push({M[i][j], {i, j}});
                    vis[i][j] = true;
                }
            }
        }
    }

    vector<int> dir = {0, 1, 0, -1, 0};

    int ans = 0;

    while (!H.empty())
    {
        auto X = H.top();
        H.pop();

        int h = X.first;
        int x = X.second.first;
        int y = X.second.second;

        for (int k = 0; k < 4; k++)
        {
            int u = x + dir[k];
            int v = y + dir[k + 1];

            if (u < 0 || u >= n || v < 0 || v >= m || vis[u][v])
                continue;

            vis[u][v] = true;

            ans += max(0, h - M[u][v]); // determine the amount of water, the terrain can contain

            int val = max(h, M[u][v]); // for the current terrain, push the highest wall in neighbour

            H.push({val, {u, v}});
        }
    }

    return ans;
}