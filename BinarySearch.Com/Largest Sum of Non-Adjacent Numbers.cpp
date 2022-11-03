#include <bits/stdc++.h>

using namespace std;

int Hamlet(vector<int> &nums, int n, int flag, vector<vector<int>> &dp)
{
    if (n <= 0)
        return 0;

    if (dp[n][flag] != -1)
        return dp[n][flag];

    int sum = INT_MIN;
    if (flag) // when true -> we can take and not take -> when take then make flag false for next turn
    {
        sum = max(sum, nums[n - 1] + Hamlet(nums, n - 1, !flag, dp));
        sum = max(sum, Hamlet(nums, n - 1, flag, dp));
    }
    else // when skip, make flag true again for next turn
        sum = max(sum, Hamlet(nums, n - 1, !flag, dp));

    return dp[n][flag] = sum;
}
int solve(vector<int> &nums)
{
    int n = nums.size();

    vector<vector<int>> dp(n + 1, vector<int>(2, -1));

    return Hamlet(nums, n, 1, dp);
}

int solve(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;

    vector<int> dp(n);
    
    dp[0] = (nums[0] >= 0) ? nums[0] : 0;
    dp[1] = (nums[1] >= 0) ? max(nums[0], nums[1]) : dp[0];
    
    for (int i = 2; i <= n; i++)
        dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
    
    return dp[n - 1];
}