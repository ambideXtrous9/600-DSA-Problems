#include <bits/stdc++.h>

using namespace std;

/*
Unbounded - KnapSack
*/

// Memoization

long long int solve(int coins[], int N, int sum, vector<vector<long long int>> &dp)
{
    if (sum == 0)
        return 1;

    if (N == 0)
        return 0;

    if (dp[N][sum] != -1)
        return dp[N][sum];

    if (sum >= coins[N - 1])
        dp[N][sum] = solve(coins, N, sum - coins[N - 1], dp) + solve(coins, N - 1, sum, dp);

    else
        dp[N][sum] = solve(coins, N - 1, sum, dp);

    return dp[N][sum];
}
long long int count(int coins[], int N, int sum)
{
    vector<vector<long long int>> dp(N + 1, vector<long long int>(sum + 1, -1));

    return solve(coins, N, sum, dp);

    // code here.
}

// Tabulation

long long int solve(int coins[], int N, int sum)
{
    vector<vector<long long int>> dp(N + 1, vector<long long int>(sum + 1, 0));

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j == 0)
                dp[i][j] = 1;
            else if (i == 0)
                dp[i][j] = 0;
            else
            {
                if (j >= coins[i - 1])
                    dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[N][sum];
}
long long int count(int coins[], int N, int sum)
{
    return solve(coins, N, sum);
}