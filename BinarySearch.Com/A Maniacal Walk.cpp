#include <bits/stdc++.h>

using namespace std;

int mod = 1e9 + 7;
int dp[501][1001];
int ways(int L, int n, int i)
{
    if (i < 0)
        return 0;

    if (i >= L)
        return 0;

    if (i == 0 && n == 0)
        return 1;

    if (n == 0 && i != 0)
        return 0;

    if (dp[n][i] != -1)
        return dp[n][i];

    return dp[n][i] = ((ways(L, n - 1, i) + ways(L, n - 1, i - 1)) % mod + ways(L, n - 1, i + 1)) % mod;
}

int solve(int length, int n)
{
    memset(dp, -1, sizeof(dp));
    return ways(length, n, 0);
}