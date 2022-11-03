#include <bits/stdc++.h>

using namespace std;

int f(vector<int> &nums, int i, int j, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MIN;
    for (int idx = i; idx <= j; idx++)
    {
        int cost = nums[i - 1] * nums[idx] * nums[j + 1] + f(nums, i, idx - 1, dp) + f(nums, idx + 1, j, dp);
        ans = max(ans, cost);
    }

    return dp[i][j] = ans;
}

int maxCoins(vector<int> &nums)
{
    int n = nums.size();
    int i = 1;
    int j = n;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    return f(nums, i, j, dp);
}

int maxCoins(vector<int> &arr)
{

    int n = arr.size();

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    arr.insert(arr.begin(), 1);
    arr.push_back(1);

    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i > j)
                continue;

            int res = INT_MIN;

            for (int k = i; k <= j; k++)
            {
                int temp = arr[i - 1] * arr[k] * arr[j + 1] + dp[i][k - 1] + dp[k + 1][j];
                res = max(res, temp);
            }
            dp[i][j] = res;
        }
    }

    return dp[1][n];
}