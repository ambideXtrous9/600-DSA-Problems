#include <bits/stdc++.h>

using namespace std;

int f(int n, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return 1e9;

    if (dp[n] != -1)
        return dp[n];

    int ans = 1e9;
    for (int i = 1; i <= sqrt(n); i++)
    {
        ans = min(ans, 1 + f(n - pow(i, 2), dp));
    }

    return dp[n] = ans;
}
int numSquares(int n)
{
    vector<int> dp(n + 1, -1);

    return f(n, dp);
}