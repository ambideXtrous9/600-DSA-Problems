#include <bits/stdc++.h>

using namespace std;

bool f(int i, int n, vector<int> &nums, vector<int> &dp)
{
    if (i >= n - 1)
        return true;
    if (nums[i] == 0)
        return false;

    if (dp[i] != -1)
        return dp[i];

    bool ans = false;

    for (int k = 1; k <= nums[i]; k++)
    {
        ans = ans || f(i + k, n, nums, dp);
        if (ans)
            break;
    }

    return dp[i] = ans;
}
bool canJump(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n + 1, -1);
    return f(0, n, nums, dp);
}