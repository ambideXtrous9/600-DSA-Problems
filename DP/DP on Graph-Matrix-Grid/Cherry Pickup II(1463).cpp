#include <bits/stdc++.h>

using namespace std;

/*
1.
When i == N-1, it means we are at the last row, so we need to return from here.
Now it can happen that at the last row, both Alice and Bob are at the same cell,
in this condition we will return only chocolates collected by Alice,
mat[i][j1]( as question states that the chocolates cannot be doubly calculated),
otherwise we return sum of chocolates collected by both, mat[i][j1] + mat[i][j1][j2].

2.
we have a total of 9 different options at every f(i,j1,j2) to move Alice and Bob.
Now we can manually write these 9 options or we can observe a pattern in them,
first Alice moves to one side and Bob tries all three choices, then again Alice moves, then Bob, and so on.
This pattern can be easily captured by using two nested loops that change the column numbers(j1 and j2).

Note: if (j1==j2), as discussed in the base case,
we will only consider chocolates collected by one of them otherwise
we will consider chocolates collected by both of them.


at every step they both will be on same row -> we take common row = i for both

*/

int maxChocoUtil(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    // base cases
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return -1e9;

    if (i == n - 1)
    {
        if (j1 == j2)
            return grid[i][j1];

        else
            return grid[i][j1] + grid[i][j2];
    }

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    // recursion

    int maxi = INT_MIN;
    for (int di = -1; di <= 1; di++)
    {
        for (int dj = -1; dj <= 1; dj++)
        {
            int ans;
            if (j1 == j2)
                ans = grid[i][j1] + maxChocoUtil(i + 1, j1 + di, j2 + dj, n, m, grid, dp);
            else
                ans = grid[i][j1] + grid[i][j2] + maxChocoUtil(i + 1, j1 + di, j2 + dj, n, m, grid, dp);

            maxi = max(maxi, ans);
        }
    }

    return dp[i][j1][j2] = maxi;
}

int cherryPickup(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

    return maxChocoUtil(0, 0, m - 1, n, m, grid, dp);
}