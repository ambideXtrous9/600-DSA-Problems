#include <bits/stdc++.h>

using namespace std;

int square(int n)
{
    return n * n;
}

int solve(vector<int> words, int n, int k, int idx, int remL, vector<vector<int>> &dp)
{
    // base case for last word
    if (idx == n)
    {
        return words[idx - 1] < remL ? 0 : square(remL);
    }
    if (dp[idx][remL] != -1)
    {
        return dp[idx][remL];
    }

    int cur = words[idx - 1];
    // if word can fit in the remaining line
    if (cur < remL)
    {
        int len = (remL == k) ? (remL - cur) : (remL - cur - 1);
        return dp[idx][remL] = min(solve(words, n, k, idx + 1, len, dp), square(remL) + solve(words, n, k, idx + 1, k - cur, dp));
    }
    else
    {
        // if word is kept on next line
        return dp[idx][remL] = square(remL) + solve(words, n, k, idx + 1, k - cur, dp);
    }
}

int solveWordWrap(vector<int> nums, int k)
{
    int n = nums.size();

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

    return solve(nums, n, k, 0, k, dp);
}

int solveWordWrap(vector<int> nums, int k)
{
    int n = nums.size();

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = n; i >= 0; i--)
    {
        for (int j = 0; j <= k; j++)
        {
            if (i == n)
            {
                dp[i][j] = nums[i - 1] < j ? 0 : square(j);
            }
            else
            {
                int cur = nums[i - 1];
                // if word can fit in the remaining line
                if (cur < j)
                {
                    int len = (j == k) ? (j - cur) : (j - cur - 1);
                    dp[i][j] = min(dp[i + 1][len], square(j) + dp[i + 1][k - cur]);
                }
                else
                {
                    // if word is kept on next line
                    dp[i][j] = square(j) + dp[i + 1][k - cur];
                }
            }
        }
    }

    return dp[0][k];
}