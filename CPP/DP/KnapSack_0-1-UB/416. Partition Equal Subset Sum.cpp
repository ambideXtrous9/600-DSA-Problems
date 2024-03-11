#include <bits/stdc++.h>

using namespace std;

int f(vector<int> &arr, int n, int sum, vector<vector<int>> &dp)
{
    if (sum == 0)
        return true;

    if (n == 0)
        return false;

    if (dp[n][sum] != -1)
        return dp[n][sum];

    if (arr[n - 1] <= sum)
        return dp[n][sum] = (f(arr, n - 1, sum - arr[n - 1], dp) || f(arr, n - 1, sum, dp));

    else
        return dp[n][sum] = f(arr, n - 1, sum, dp);
}

bool canPartition(vector<int> &nums)
{
    int n = nums.size();

    int sum = 0;

    for (auto x : nums)
        sum += x;

    if (sum % 2)
        return false;

    vector<vector<int>> dp(n + 1, vector<int>((sum / 2) + 1, -1));

    return f(nums, n, sum / 2, dp);
}