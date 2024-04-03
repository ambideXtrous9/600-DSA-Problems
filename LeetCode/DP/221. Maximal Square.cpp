#include <bits/stdc++.h>

using namespace std;

int maximalSquare(vector<vector<char>> &matrix)
{
    if (matrix.empty())
    {
        return 0;
    }
    int m = matrix.size(), n = matrix[0].size(), sz = 0;
    
    vector<vector<int>> dp(m, vector<int>(n, 0));
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!i || !j || matrix[i][j] == '0')
            {
                dp[i][j] = matrix[i][j] - '0';
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
            sz = max(dp[i][j], sz);
        }
    }
    return sz * sz;
}

// Number of Islands Number of Islands Solution

int DFS(int i, int j, vector<vector<char>> &M,vector<vector<int>> &dp)
{
    if (i < 0 || j < 0 || i >= M.size() || j >= M[0].size() || M[i][j] == '0')
        return 0;
    
    if (dp[i][j] != -1)
        return dp[i][j];

    return dp[i][j] = 1 + min({DFS(i + 1, j, M,dp),DFS(i + 1, j + 1, M,dp),DFS(i, j + 1, M,dp)});
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
                ans = max(ans, DFS(i, j, matrix,dp));
            }
        }
    }
    return ans == INT_MIN ? 0 : ans * ans;
}