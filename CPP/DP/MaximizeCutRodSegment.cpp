#include <bits/stdc++.h>

using namespace std;

int f(int n, int x, int y, int z, vector<int> &dp)
{
    int xs = 0, ys = 0, zs = 0;
    if (n == 0)
        return 0;
    if (n < 0)
        return INT_MIN;
    if (dp[n] != -1)
        return dp[n];
    xs = 1 + f(n - x, x, y, z, dp);
    ys = 1 + f(n - y, x, y, z, dp);
    zs = 1 + f(n - z, x, y, z, dp);
    return dp[n] = max(xs, max(ys, zs));
}
int maximizeTheCuts(int n, int x, int y, int z)
{
    // Your code here
    vector<int> dp(n + 1, -1);
    int max = 0;
    max = f(n, x, y, z, dp);
    if (max < 0)
        return 0;
    else
        return max;
}

int maximizeTheCuts(int n, int x, int y, int z)
{
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = INT_MIN;
        // negative ke liya condition lgayi hai
        if (i - x >= 0)
            dp[i] = max(dp[i], dp[i - x]);
        if (i - y >= 0)
            dp[i] = max(dp[i], dp[i - y]);
        if (i - z >= 0)
            dp[i] = max(dp[i], dp[i - z]);

        if (dp[i] != INT_MIN)
            dp[i]++;
    }
    if (dp[n] < 0)
        return 0;
    return dp[n];
}