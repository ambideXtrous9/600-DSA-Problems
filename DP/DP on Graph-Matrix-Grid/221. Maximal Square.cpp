#include <bits/stdc++.h>

using namespace std;

// 24.Max Size Square SubMatrix

int DFS(int i, int j, vector<vector<char>> &M, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0 || i >= M.size() || j >= M[0].size() || M[i][j] == '0')
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    return dp[i][j] = 1 + min({DFS(i + 1, j, M, dp), DFS(i + 1, j + 1, M, dp), DFS(i, j + 1, M, dp)});
}
int maximalSquare(vector<vector<char>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int ans = INT_MIN;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == '1')
            {
                ans = max(ans, DFS(i, j, matrix, dp));
            }
        }
    }
    return ans == INT_MIN ? 0 : ans * ans;
}

int maximalSquare(vector<vector<char>> &M)
{
    int n = M.size();
    int m = M[0].size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || j == 0)
            {
                if (M[i][j] == '0')
                    dp[i][j] = 0;
                else
                {
                    dp[i][j] = 1;
                }
            }

            else if (M[i][j] == '1')
            {
                dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
            }

            ans = max(ans, dp[i][j]);
        }
    }

    return ans * ans;
}