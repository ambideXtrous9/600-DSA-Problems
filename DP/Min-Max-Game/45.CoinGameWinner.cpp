#include <bits/stdc++.h>

using namespace std;

bool findWinner(int x, int y, int n)
{
    if (n == 0)
        return false;
    if (n == 1)
        return true;

    bool a = true, b = true, c = true;

    if (n - x >= 0)
        b = findWinner(x, y, n - x);
    if (n - y >= 0)
        c = findWinner(x, y, n - y);
    if (n - 1 >= 0)
        a = findWinner(x, y, n - 1);

    if (!a || !b || !c)
        return true;

    return false;
}

int solve(int n, int x, int y, vector<int> &dp)
{
    if (n == 0)
        return false;
    if (n == 1)
        return true;
    if (dp[n] != -1)
        return dp[n];

    int a = true, b = true, c = true;

    if (n - x >= 0)
        a = solve(n - x, x, y, dp);

    if (n - y >= 0)
        b = solve(n - y, x, y, dp);

    if (n - 1 >= 0)
        c = solve(n - 1, x, y, dp);

    if (!a || !b || !c)
        return dp[n] = 1;

    return dp[n] = 0;
}

int findWinner2(int N, int X, int Y)
{
    vector<int> dp(N + 1, -1);
    return solve(N, X, Y, dp);
}

int findWinner2(int N, int x, int y)
{
    vector<int> dp(N + 1, 0);

    for (int i = 0; i <= N; i++)
    {
        if (i == 0)
            dp[i] = false;
        else if (i == 1)
            dp[i] = true;

        else
        {
            bool a = true, b = true, c = true;

            if (i - x >= 0)
                a = dp[i - x];

            if (i - y >= 0)
                b = dp[i - y];

            if (i - 1 >= 0)
                c = dp[i - 1];

            if (!a || !b || !c)
                dp[i] = true;
            else
                dp[i] = false;
        }
    }
    return dp[N];
}
