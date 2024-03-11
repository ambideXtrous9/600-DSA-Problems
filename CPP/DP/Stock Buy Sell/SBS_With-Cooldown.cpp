#include <bits/stdc++.h>

using namespace std;


/*

309. Best Time to Buy and Sell Stock with Cooldown

*/

int dp[5001][2];

int stock(vector<int> &arr, int i, int buy, int n)
{
    if (i >= n)
        return 0;

    if (dp[i][buy] != -1)
        return dp[i][buy];

    int profit = stock(arr, i + 1, buy, n);

    if (buy)
    {
        profit = max(profit, -arr[i] + stock(arr, i + 1, !buy, n));
    }
    else
    {
        profit = max(profit, arr[i] + stock(arr, i + 2, !buy, n));
    }

    return dp[i][buy] = profit;
}

int maxProfit(vector<int> &arr)
{

    int n = arr.size();

    memset(dp, -1, sizeof(dp));

    return stock(arr, 0, 1, n);
}

int maxProfit(vector<int> &arr)
{
    int n = arr.size();

    vector<vector<int>> dp(n + 2, vector<int>(2, 0));

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
                profit = max(profit, arr[i] + dp[i + 2][!buy]);
            }

            dp[i][buy] = profit;
        }
    }

    return dp[0][1];
}