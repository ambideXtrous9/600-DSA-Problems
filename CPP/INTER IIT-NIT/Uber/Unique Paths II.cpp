#include <bits/stdc++.h>

using namespace std;

int DFS(vector<vector<int>> &G, int i, int j, int m, int n, vector<vector<int>> &dp)
{
    if (i < 0 || i >= m || j < 0 || j >= n || G[i][j] == 1)
        return 0;

    if (i == m - 1 && j == n - 1)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    return dp[i][j] = DFS(G, i + 1, j, m, n, dp) + DFS(G, i, j + 1, m, n, dp);
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    int res = 0;

    res = DFS(obstacleGrid, 0, 0, m, n, dp);

    return res;
}