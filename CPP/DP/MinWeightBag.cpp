#include <bits/stdc++.h>

using namespace std;

int dp[201][201];

int helper(int cost[], int n, int w)
{
    if (w == 0)
        return (0);
    if (n == 0 || w < 0)
        return (INT_MAX);

    if (dp[n][w] != -1)
        return (dp[n][w]);

    if (n <= w && cost[n - 1] != -1)
    {
        if(helper(cost, n, w - n)!=INT_MAX)
            return dp[n][w] = min(cost[n - 1] + helper(cost, n, w - n), helper(cost, n - 1, w));
        else
            return dp[n][w] = helper(cost, n - 1, w);
    }
    return dp[n][w] = helper(cost, n - 1, w);
}

int minimumCost(int cost[], int N, int W)
{
    memset(dp, -1, sizeof(dp));
    int res = helper(cost, N, W);
    return res == INT_MAX ? -1 : (int)res;
}

int minimumCost(int cost[], int N, int W)
{
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0)
                dp[i][j] = INT_MAX;

            else if (j == 0)
                dp[i][j] = 0;

            else if (i <= j && cost[i - 1] != -1)
            {
                if (dp[i][j - i] != INT_MAX)
                    dp[i][j] = min(cost[i - 1] + dp[i][j - i], dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    if (dp[N][W] != INT_MAX)
        return dp[N][W];
    return -1;
}