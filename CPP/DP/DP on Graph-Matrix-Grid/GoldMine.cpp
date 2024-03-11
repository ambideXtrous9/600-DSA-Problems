#include <bits/stdc++.h>

using namespace std;

// same as max/min falling path

int solve(int i, int j, int m, int n, vector<vector<int>> &arr, vector<vector<int>> &dp)
{
    if (i < 0 || i >= n || j >= m || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    // upwards diagonaly
    int x = solve(i - 1, j + 1, m, n, arr, dp);
    // downwards diagonaly
    int y = solve(i + 1, j + 1, m, n, arr, dp);
    // right
    int z = solve(i, j + 1, m, n, arr, dp);
    // maximum of all

    return dp[i][j] = arr[i][j] + max({x, y, z});
}
int maxGold(int n, int m, vector<vector<int>> M)
{
    // code here

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    int maxi = 0;

    for (int i = 0; i < n; i++)
    {
        int ans = solve(i, 0, m, n, M, dp);
        maxi = max(maxi, ans);
    }
    return maxi;
}

int maxGold(int n, int m, vector<vector<int>> M)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    int res = INT_MIN;
    
    for (int j = 0; j <= m - 1; j++)
    {
        for (int i = 0; i <= n - 1; i++)
        {
            if (j == 0)
                dp[i][j] = M[i][j];
            else
            {
                int UD = INT_MIN;
                if (i - 1 >= 0)
                    UD = M[i][j] + dp[i - 1][j - 1];

                int LD = INT_MIN;
                if (i + 1 < n)
                    LD = M[i][j] + dp[i + 1][j - 1];

                int R = INT_MIN;
                R = M[i][j] + dp[i][j - 1];

                dp[i][j] = max(UD, max(LD, R));
            }

            res = max(res, dp[i][j]);
        }
    }

    return res;
}

int maxGold(int n, int m, vector<vector<int>> mat)
{
    int res = INT_MIN;
    for (int j = 1; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            int up = (i - 1 >= 0 ? mat[i - 1][j - 1] : 0);
            int dn = (i + 1 < n ? mat[i + 1][j - 1] : 0);
            mat[i][j] += max({up, dn, mat[i][j - 1]});
        }
    }
    for (int i = 0; i < n; i++)
        res = max(res, mat[i][m - 1]);
    return res;
}