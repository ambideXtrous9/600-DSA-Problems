#include <bits/stdc++.h>

using namespace std;

/*

714. Best Time to Buy and Sell Stock with Transaction Fee

*/

int stock(vector<int> &arr, int i, int buy, int n, int fee, vector<vector<int>> &dp)
{
    if (i >= n)
        return 0;

    if (dp[i][buy] != -1)
        return dp[i][buy];

    // skip the buy n sell
    int cost = stock(arr, i + 1, buy, n, fee, dp);

    // buy the stock -> spending money so -
    if (buy)
        cost = max(cost, -arr[i] + stock(arr, i + 1, !buy, n, fee, dp));

    // sell the stock -> getting money back by sell so +
    if (!buy)
        cost = max(cost, arr[i] - fee + stock(arr, i + 1, !buy, n, fee, dp));

    return dp[i][buy] = cost;
}
int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(3, -1));

    return stock(prices, 0, 1, n, fee, dp);
}

int maxProfit(vector<int> &arr, int fee)
{
    int n = arr.size();

    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 1; buy >= 0; buy--)
        {
            int profit = dp[i + 1][buy];

            if (buy)
            {
                profit = max(profit, -arr[i] + dp[i + 1][!buy]);
            }
            else
            {
                profit = max(profit, arr[i] - fee + dp[i + 1][!buy]);
            }

            dp[i][buy] = profit;
        }
    }

    return dp[0][1];
}