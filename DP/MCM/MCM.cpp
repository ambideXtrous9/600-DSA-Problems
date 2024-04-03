#include <bits/stdc++.h>

using namespace std;

int solve(int arr[], vector<vector<int>> &dp, int i, int j)
{
    if (i >= j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int res = INT_MAX;

    for (int k = i; k < j; k++)
    {
        int temp = arr[i - 1] * arr[k] * arr[j] + solve(arr, dp, i, k) + solve(arr, dp, k + 1, j);
        res = min(res, temp);
    }
    return dp[i][j] = res;
}

int matrixMultiplication(int n, int arr[])
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    return solve(arr, dp, 1, n - 1);
}

int matrixMultiplication(int n, int arr[])
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            int res = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int temp = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                res = min(res, temp);
            }
            dp[i][j] = res;
        }
    }

    return dp[1][n - 1];
}

// 1039. Minimum Score Triangulation of Polygon

int minScoreTriangulation(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            int res = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int temp = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                res = min(res, temp);
            }
            dp[i][j] = res;
        }
    }

    return dp[1][n - 1];
}
