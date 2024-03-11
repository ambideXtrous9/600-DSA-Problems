#include <bits/stdc++.h>

using namespace std;

// 746. Min Cost Climbing Stairs

int Hamlet(vector<int> nums, int n, int allow, vector<vector<int>> &dp)
{
    if (n == 0)
        return 0;

    if (dp[n][allow] != -1)
        return dp[n][allow];

    int take = INT_MAX;

    if (allow)
    {
        take = min(take, nums[n - 1] + Hamlet(nums, n - 1, allow, dp));
        take = min(take, Hamlet(nums, n - 1, !allow, dp));
    }
    else
        take = min(take, nums[n - 1] + Hamlet(nums, n - 1, !allow, dp));

    return dp[n][allow] = take;
}

int dp[100001];
int Hamlet(vector<int> nums,int n,int i)
{
    if(i>=n) return 0;

    if(dp[i]!=-1) return dp[i];

    return dp[i] = nums[i] + min(Hamlet(nums,n,i+1),Hamlet(nums,n,i+2));
}

int solve(vector<int>& nums) 
{
    int n = nums.size();

    memset(dp,-1,sizeof(dp));

   return min(Hamlet(nums,n,0),Hamlet(nums,n,1));
    
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

    if (n == 1)
        return nums[0];

    if (n == 2)
        return min(nums[0], nums[1]);

    vector<int> dp(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        if (i < 2)
            dp[i] = nums[i];
        else
            dp[i] = nums[i] + min(dp[i - 1], dp[i - 2]);
    }

    return min(dp[n - 1], dp[n - 2]);
}