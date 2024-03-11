#include <bits/stdc++.h>

using namespace std;

/*
Think of it as a problem where 2 people start fetching cherries from (0, 0) and
both can move either left or bottom and both try to reach destination (N-1, N-1).
At any point of time both must have been moved same number of steps and hence:

r1+c1 = r2+c2 (as both move by only one cell at a time)

r2 = r1 + c1 - c2


Also, keep a check of whether at a certain point, they both are at same point,
if they are-> count cherry of that cell only once in the answer.

Traverse the rest of the grid, with 4 possibitlies-
person 1 moving left or bottom * person 2 moving left or bottom.

*/

int dp[51][51][51];

int DFS(vector<vector<int>> &M, int r1, int c1, int c2, int n)
{
    int r2 = r1 + c1 - c2;

    if (r1 < 0 || c1 < 0 || r2 < 0 || r2 >= n || r1 >= n || c1 >= n || c2 < 0 || c2 >= n || M[r1][c1] == -1 || M[r2][c2] == -1)
        return INT_MIN;

    if (r1 == n - 1 && c1 == n - 1)
        return M[r1][c1];

    if (dp[r1][c1][c2] != -1)
        return dp[r1][c1][c2];

    int ans = M[r1][c1];

    if (r1 != r2 && c1 != c2)
        ans += M[r2][c2];

    ans += max({
        DFS(M, r1, c1 + 1, c2, n),
        DFS(M, r1, c1 + 1, c2 + 1, n),
        DFS(M, r1 + 1, c1, c2, n),
        DFS(M, r1 + 1, c1, c2 + 1, n),
    });

    return dp[r1][c1][c2] = ans;
}

int cherryPickup(vector<vector<int>> &grid)
{
    memset(dp, -1, sizeof(dp));
    int n = grid.size();

    return max(0, DFS(grid, 0, 0, 0, n));
}