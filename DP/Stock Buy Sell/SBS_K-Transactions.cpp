#include <bits/stdc++.h>

using namespace std;

/*
LC
121. Best Time to Buy and Sell Stock
123. Best Time to Buy and Sell Stock III
188. Best Time to Buy and Sell Stock IV
*/

int stock(vector<int> &arr, int i, int buy, int k, int n, vector<vector<vector<int>>> &dp)
{
    if (i == n || k<=0)
        return 0;

    if (dp[i][buy][k] != -1)
        return dp[i][buy][k];



    int ans = stock(arr, i + 1, buy, k, n, dp);

    if (buy && k)
        ans = max(ans, -arr[i] + stock(arr, i + 1, !buy, k, n, dp));

    else
        ans = max(ans, arr[i] + stock(arr, i + 1, !buy, k - 1, n, dp));

    return dp[i][buy][k] = ans;
}

int solve(vector<int> &arr)
{
    int n = arr.size();
    int k = 2;

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2 + 1, vector<int>(k + 1, -1)));

    int buy = true;
    return stock(arr, 0, buy, k, n, dp);
}

int maxProfit(vector<int> &arr)
{
    int n = arr.size();
    int k = 2;

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 1; buy >= 0; buy--)
        {
            for (int cap = 1; cap <= k; cap++)
            {
                int ans = dp[i + 1][buy][cap];

                if (buy && cap)
                    ans = max(ans, -arr[i] + dp[i + 1][!buy][cap]);

               else
                    ans = max(ans, arr[i] + dp[i + 1][!buy][cap - 1]);

                dp[i][buy][cap] = ans;
            }
        }
    }

    return dp[0][1][k];
}

int maxProfit(vector<int> &arr)
{
    int n = arr.size();
    int k = 2;

    vector<vector<int>> ahead(2, vector<int>(k + 1, 0));

    vector<vector<int>> cur(2, vector<int>(k + 1, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 1; buy >= 0; buy--)
        {
            for (int cap = 1; cap <= k; cap++)
            {
                int ans = ahead[buy][cap];

                if (buy && cap)
                    ans = max(ans, -arr[i] + ahead[!buy][cap]);

                else
                    ans = max(ans, arr[i] + ahead[!buy][cap - 1]);

                cur[buy][cap] = ans;
            }
        }

        ahead = cur;
    }

    return cur[1][k];
}

int maxProfit(int k, int n, int a[])
{
    int dp[k + 1][n];
    
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



