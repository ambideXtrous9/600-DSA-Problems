#include <bits/stdc++.h>

using namespace std;

int findLength(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int res = 0;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
            res = max(res, dp[i][j]);
        }
    }

    return res;
}

int f(int i, int j, vector<int> &S1, vector<int> &S2, vector<vector<int>> &dp, int &ans)
{
    int take = 0, nottake1 = 0, nottake2 = 0;

    if (i == 0 || j == 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (S1[i - 1] == S2[j - 1])
        take = 1 + f(i - 1, j - 1, S1, S2, dp, ans);

    nottake1 = f(i - 1, j, S1, S2, dp, ans);

    nottake2 = f(i, j - 1, S1, S2, dp, ans);

    ans = max(ans, take);

    return dp[i][j] = take;
}


int findLength(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();

    int ans = 0;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    f(n, m, nums1, nums2, dp, ans);

    return ans;
}