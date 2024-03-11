#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int min_so_far = prices[0];
    int profit = 0;

    for (int i = 1; i < prices.size(); ++i)
    {

        if (prices[i] - min_so_far > profit)
        {
            profit = prices[i] - min_so_far;
        }

        if (prices[i] < min_so_far)
        {
            min_so_far = prices[i];
        }
    }

    return profit;
}

int stock(vector<int> &arr, int i, int buy, int k, int n, vector<vector<vector<int>>> &dp)
{
    if (i == n)
        return 0;

    if (dp[i][buy][k] != -1)
        return dp[i][buy][k];

    int ans = stock(arr, i + 1, buy, k, n, dp);

    if (buy && k)
        ans = max(ans, -arr[i] + stock(arr, i + 1, 0, k, n, dp));

    if (!buy)
        ans = max(ans, arr[i] + stock(arr, i + 1, 1, k - 1, n, dp));

    return dp[i][buy][k] = ans;
}
int maxProfit(vector<int> &arr)
{
    int n = arr.size();
    int k = 1;

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2 + 1, vector<int>(k + 1, -1)));

    int buy = true;
    return stock(arr, 0, buy, k, n, dp);
}

int maxProfit(vector<int> &a)
{
    int n = a.size();
    int k = 1;

    int dp[k + 1][n + 1];

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= k; i++)
    {
        int mx = INT_MIN;

        for (int j = 1; j < n; j++)
        {
            mx = max(mx, -a[j - 1] + dp[i - 1][j - 1]);
            dp[i][j] = max(dp[i][j - 1], mx + a[j]);
        }
    }
    return dp[k][n - 1];
}