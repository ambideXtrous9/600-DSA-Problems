#include <bits/stdc++.h>

using namespace std;

int DFS(vector<vector<int>> &M, int i, int j, int n, int m, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0 || i >= n || j >= m || M[i][j] == 0)
    {
        return 0;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    return dp[i][j] = 1 + min({DFS(M, i + 1, j + 1, n, m, dp), DFS(M, i + 1, j, n, m, dp), DFS(M, i, j + 1, n, m, dp)});
}

int solve(vector<vector<int>> &M)
{

    int ans = 0;

    int n = M.size();
    int m = M[0].size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] == 1)
            {
                int X = DFS(M, i, j, n, m, dp);
                ans = max(ans, X);
            }
        }
    }

    return ans * ans;
}

int solve(vector<vector<int>> &m)
{
    int row = m.size();
    
    int col = m[0].size();
    
    int maxi = 0;

    vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
    
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if (m[i - 1][j - 1] == 1)
            {
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
                maxi = max(maxi, dp[i][j]);
            }
        }
    }
    return maxi * maxi;
}