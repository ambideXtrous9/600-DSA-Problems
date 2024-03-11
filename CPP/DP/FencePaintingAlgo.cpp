//(F(n-1)+F(n-2))*(k-1).
#include <bits/stdc++.h>

using namespace std;

int mod = 1e9 + 7;
long long countWays(int n, int k)
{
    // code here
    if (n == 0)
        return 0;
    if (n == 1)
        return k;
    if (n == 2)
        return k * k;

    return ((k - 1) * (countWays(n - 1, k) + countWays(n - 2, k))) % mod;
}

int mod = 1e9 + 7;
long long int Ways(int n, int k, vector<vector<long long int>> &dp)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return k;
    if (n == 2)
        return k * k;

    if (dp[n][k] != -1)
        return dp[n][k];

    return dp[n][k] = ((k - 1) * (Ways(n - 1, k, dp) + Ways(n - 2, k, dp))) % mod;
}

long long int countWays(int n, int k)
{
    vector<vector<long long int>> dp(n + 1, vector<long long int>(k + 1, -1));
    return Ways(n, k, dp);
}

long long int countWays(int n, int k)
{
    vector<long long int> dp(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
            dp[i] = 0;
        if (i == 1)
            dp[i] = k;
        if (i == 2)
            dp[i] = k * k;

        else
        {
            dp[i] = ((k - 1) * (dp[i - 1] + dp[n - 2])) % mod;
        }
    }
    return dp[n];
}