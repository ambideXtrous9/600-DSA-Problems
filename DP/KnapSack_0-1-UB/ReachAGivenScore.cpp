#include <bits/stdc++.h>

using namespace std;

long long int UBKS(int N, int W, int wt[])
{

    vector<vector<long long int>> dp(N + 1, vector<long long int>(W + 1, 0));

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0)
                dp[i][j] = 0;

            else if (j == 0)
                dp[i][j] = 1;

            else if (wt[i - 1] <= j)
            {
                dp[i][j] = dp[i][j - wt[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[N][W];
}
long long int count(long long int w)
{
    long long int table[w + 1], i;
    memset(table, 0, sizeof(table));
    table[0] = 1;
    // If 0 sum is required number of ways is 1.
    int arr[] = {3, 5, 10};

    table[w] = UBKS(3, w, arr);

    // Your code here
    return table[w];
}

long long int count(long long int n)
{
    long long int dp[n + 1], i;
    memset(dp, 0, sizeof(dp));
    
    dp[0] = 1;

    for (int i = 3; i <= n; i++)
        dp[i] += dp[i - 3];

    for (int i = 5; i <= n; i++)
        dp[i] += dp[i - 5];
    
    for (int i = 10; i <= n; i++)
        dp[i] += dp[i - 10];
    
    return dp[n];
}