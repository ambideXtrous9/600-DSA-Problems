#include <bits/stdc++.h>

using namespace std;

int dp[101];

int KS(vector<int> &nums, int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return nums[n - 1];

    if (dp[n] != -1)
        return dp[n];

    int take = nums[n - 1] + KS(nums, n - 2);

    int nottake = KS(nums, n - 1);

    return dp[n] = max(take, nottake);
}

int rob(vector<int> &nums)
{
    int n = nums.size();

    memset(dp, -1, sizeof(dp));

    return KS(nums, n);
}

int KS(vector<int> &nums, int n)
{
    vector<int> dp(n + 1, 0);

    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
            dp[i] = 0;

        else if (i == 1)
        {
            dp[i] = nums[i - 1];
        }

        else
        {
            int take = nums[i - 1];
            int nottake = 0;

            if (i - 2 >= 0)
                take += dp[i - 2];

            nottake = dp[i - 1];

            dp[i] = max(take, nottake);
        }
    }

    return dp[n];
}

int rob(vector<int> &nums)
{
    int n = nums.size();

    return KS(nums, n);
}

int KS(vector<int> &nums, int n)
{
    int prev = 0;
    int prev2 = 0;
    int cur = 0;

    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
            cur = 0;

        else if (i == 1)
        {
            prev = nums[i - 1];
        }

        else
        {
            int take = nums[i - 1];
            int nottake = 0;

            if (i - 2 >= 0)
                take += prev2;

            nottake = prev;

            cur = max(take, nottake);

            prev2 = prev;
            prev = cur;
        }
    }

    return prev;
}

int rob(vector<int> &nums)
{
    int n = nums.size();

    return KS(nums, n);
}