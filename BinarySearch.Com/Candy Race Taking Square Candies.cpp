#include <bits/stdc++.h>

using namespace std;

bool candy(int n, int player, vector<vector<int>> &dp)
{
    if (n == 0 && player == 0)
        return false; // nothing to pick and my turn -> I  lose

    if (n == 0 && player == 1)
        return true; // nothing to pick and P2's turn -> I win

    if (dp[n][player] != -1)
        return dp[n][player];

    for (int i = 1; i <= sqrt(n); i++)
    {
        int res = candy(n - (i * i), !player, dp);

        if (res && player == 0)  // my turn and f() returns true -> I win
            return dp[n][player] = true;

        if (!res && player == 1)  // P2's turn and f() returns false -> I lose(P2 win)
            return dp[n][player] = false;
    }

    // in any other cases 

    if (player == 0)   // if my turn -> I lose
        return dp[n][player] = false;
    else // if P2's turn -> I win
        return dp[n][player] = true;
}

int solve(int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));

    return candy(n, 0, dp);
}
