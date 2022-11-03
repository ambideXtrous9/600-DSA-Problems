#include <bits/stdc++.h>

using namespace std;

vector<int> LIS(vector<int> &nums)
{
    int n = nums.size();

    vector<int> V;
    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++)
    {
        if (V.size() == 0 || nums[i] > V.back())
        {
            V.push_back(nums[i]);
            dp[i] = V.size();
        }
        else
        {
            int idx = lower_bound(V.begin(), V.end(), nums[i]) - V.begin();

            V[idx] = nums[i];
            dp[i] = (idx + 1);
        }
    }

    return dp;
}

int minimumMountainRemovals(vector<int> &nums)
{
    int n = nums.size();

    vector<int> lis = LIS(nums);

    reverse(nums.begin(), nums.end());

    vector<int> lrs = LIS(nums);

    reverse(lrs.begin(), lrs.end());

    int res = 0;

    for (int i = 0; i < n; i++)
    {
        // If either dpleft[i] or dpright[i] = 1, then it means that the sequence is either strictly increasing/decreasing.
        if (lis[i] > 1 && lrs[i] > 1)
            res = max(res, lis[i] + lrs[i] - 1);
    }

    return n - res;
}