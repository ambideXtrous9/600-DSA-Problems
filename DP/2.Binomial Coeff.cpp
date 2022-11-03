#include <bits/stdc++.h>

using namespace std;

int mod = 1e9 + 7;

int solve(int n, int r, vector<vector<int>> &dp)
{
    // base case
    if (n < r)
    {
        return 0;
    }

    if (r == 1)
        return n;

    if (r == 0 || r == n)
    {
        return 1;
    }

    if (dp[n][r] != -1)
    {
        return dp[n][r];
    }
    // NCR means selecting the r objects from n objects

    // case 1 : we selected the 1 object from the n object than
    int taken = solve(n - 1, r - 1, dp);

    // case 2 : we leave the 1st object form the n object then
    int notTaken = solve(n - 1, r, dp);

    dp[n][r] = (taken + notTaken) % mod;

    return dp[n][r];
}

int nCr(int n, int r)
{
    vector<vector<int>> dp(n + 1, vector<int>(r + 1, -1));
    return solve(n, r, dp);
}

int nCr(int n, int r)
{
    vector<vector<int>> dp(n + 1, vector<int>(r + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= r; j++)
        {
            if (j == 0 || i == j)
                dp[i][j] = 1;
            else if (j > i)
                dp[i][j] = 0;
            else if (j == 1)
                dp[i][j] = i;
            else
            {
                dp[i][j] = ((dp[i - 1][j - 1] % mod) + (dp[i - 1][j] % mod)) % mod;
            }
        }
    }

    return dp[n][r];
}