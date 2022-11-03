#include <bits/stdc++.h>

using namespace std;

int findTargetSumWays(vector<int> &nums, int target)
{

    int sum = 0;

    int n = nums.size();

    int zerocnt = 0;

    for (auto x : nums)
    {
        if (x == 0)
            zerocnt++;
        sum += x;
    }

    if (abs(target) > sum || (sum + target) % 2)
        return 0;

    int S = (sum + target) / 2;

    vector<vector<int>> dp(n + 1, vector<int>(S + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= S; j++)
        {
            if (j == 0)
                dp[i][j] = 1;

            else if (i == 0)
                dp[i][j] = 0;

            else
            {
                if (j >= nums[i - 1] && nums[i - 1] != 0)
                {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][S] * pow(2, zerocnt);
}