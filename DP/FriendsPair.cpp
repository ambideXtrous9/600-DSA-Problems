#include <bits/stdc++.h>

using namespace std;

int mod = (int)1e9 + 7;
long long int dp[10001];

long long int helper(int n)
{
    if (n == 1)
        return (1);
    if (n == 2)
        return (2);

    if (dp[n] != -1)
        return (dp[n]);

    return dp[n] = (helper(n - 1) + (n - 1) * helper(n - 2)) % mod;
}

int countFriendsPairings(int n)
{
    memset(dp, -1, sizeof(dp));
    return (int)helper(n);
}

int countFriendsPairings(int n)
{
    int dp[n + 1];

    // Filling dp[] in bottom-up manner using
    // recursive formula explained above.
    for (int i = 0; i <= n; i++)
    {
        if (i <= 2)
            dp[i] = i;
        else
            dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
    }

    return dp[n];
}