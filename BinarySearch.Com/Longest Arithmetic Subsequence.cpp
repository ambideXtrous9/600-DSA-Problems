#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &nums)
{

    int n = nums.size();

    if (n <= 2)
        return n;

    unordered_map<int, unordered_map<int, int>> dp;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int d = nums[j] - nums[i];

            dp[d][j] = max(dp[d][i] + 1,2);
            
            ans = max(ans, dp[d][j]);
        }
    }

    return ans;
}

int solve(vector<int>& nums) 
{

    int n = nums.size();
    int ans = 0;

    if (n <= 2)
        return n;

    vector<vector<int>> dp(n+1, vector<int>(5001, 0)); // based on constraints

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int d = nums[j] - nums[i] + 1000; // coordinate shift avoid negative index

            dp[j][d] = max(dp[i][d] + 1, 2);

            ans = max(ans, dp[j][d]);
        }
    }

    return ans;
}