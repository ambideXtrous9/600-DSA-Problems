#include <bits/stdc++.h>

using namespace std;

int LIS(int cur, int prev, int n, int arr[], vector<vector<int>> &dp)
{
    if (cur == n)
        return 0;

    if (dp[cur][prev + 1] != -1)
        return dp[cur][prev + 1]; // coordinate shift

    int len = 0 + LIS(cur + 1, prev, n, arr, dp); // not taken

    if (prev == -1 || abs(arr[cur] - arr[prev]) == 1)
    {
        len = max(len, 1 + LIS(cur + 1, cur, n, arr, dp));
    }

    return dp[cur][prev + 1] = len; // coordinate shift
}

int longestSubsequence(int n, int arr[])
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return LIS(0, -1, n, arr, dp);
}

int LIS(int n, vector<int> &arr)
{
    vector<int> dp(n + 1, 1);
    int res = INT_MIN;
    for (int cur = 0; cur < n; cur++)
    {
        for (int prev = 0; prev < cur; prev++)
        {
            if (abs(arr[cur] - arr[prev])==1)
            {
                dp[cur] = max(dp[cur], dp[prev] + 1);
            }
        }
        res = max(res, dp[cur]);
    }

    return res;
}