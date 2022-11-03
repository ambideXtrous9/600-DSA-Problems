#include <bits/stdc++.h>

using namespace std;

int dp[201][201];

int DFS(vector<vector<int>> &dungeon, int i, int j, int n, int m)
{
    if (i >= n || j >= m)
    {
        return 1e9;
    }

    if (i == n - 1 && j == m - 1)
    {
        if (dungeon[i][j] > 0)
            return 1; //

        else
            return 1 - dungeon[i][j]; // if d[i][j] = -5 to overcome we need at least 1-(-5) = 6
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    // now value we get as return from right or down is the amount of energy
    // needed if we move in either direction

    int right = DFS(dungeon, i, j + 1, n, m);
    int down = DFS(dungeon, i + 1, j, n, m);

    // subtract current energy gives us whether we can move or not
    int res = min(right, down) - dungeon[i][j];

    // if min energy is greater than current we need at least positive energy +1
    // otherwise we can we can cross with leftover energy needed fron next term.
    return dp[i][j] = res > 0 ? res : 1;
}

int calculateMinimumHP(vector<vector<int>> &dungeon)
{
    int n = dungeon.size();
    int m = dungeon[0].size();

    memset(dp, -1, sizeof(dp));

    return DFS(dungeon, 0, 0, n, m);
}

int calculateMinimumHP(vector<vector<int>> &M)
{
    int n = M.size();
    int m = M[0].size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = n; i >= 0; i--)
    {
        for (int j = m; j >= 0; j--)
        {

            if (i == n || j == m)
                dp[i][j] = 1e9;

            else if (i == n - 1 && j == m - 1)
                dp[i][j] = M[i][j] > 0 ? 1 : 1 - M[i][j];

            else
            {

                int right = dp[i][j + 1];
                int left = dp[i + 1][j];

                int res = min(right, left) - M[i][j];

                dp[i][j] = res > 0 ? res : 1;
            }
        }
    }

    return dp[0][0];
}
