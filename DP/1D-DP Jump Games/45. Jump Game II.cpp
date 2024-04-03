#include <bits/stdc++.h>

using namespace std;

int f(int i, int n, vector<int> &nums, vector<int> &dp)
{
    if (i >= n - 1)
        return 0;

    if (nums[i] == 0)
        return 1e9;

    if (dp[i] != -1)
        return dp[i];

    int ans = 1e9;

    for (int k = 1; k <= nums[i]; k++)
    {
        ans = min(ans, 1 + f(i + k, n, nums, dp));
    }

    return dp[i] = ans;
}
int jump(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n + 1, -1);
    return f(0, n, nums, dp);
}