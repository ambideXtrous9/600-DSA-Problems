#include <bits/stdc++.h>

using namespace std;

int MaxSq(vector<vector<int>> &M, int i, int j, vector<vector<int>> &dp, int &res)
{
    if (i == 0 || j == 0)
        return 1;

    else if (dp[i][j] != -1)
        return dp[i][j];

    int LC = MaxSq(M, i - 1, j - 1, dp, res);
    int U = MaxSq(M, i - 1, j, dp, res);
    int L = MaxSq(M, i, j - 1, dp, res);

    if (M[i - 1][j - 1] == M[i][j] && M[i - 1][j] == M[i][j] && M[i][j - 1] == M[i][j])
    {
        dp[i][j] = 1 + min({LC, L, U});
    }
    else
        dp[i][j] = 1;

    res = max(res, dp[i][j]);

    return dp[i][j];
}

int solve(vector<vector<int>> &M)
{
    int n = M.size();
    int m = M[0].size();

    int res = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    int X = MaxSq(M, n - 1, m - 1, dp, res);

    return res = max(res, X);
}

int largestKSubmatrix(vector<vector<int>> &a)
{
    int Row = a.size();
    int Col = a[0].size();
    vector<vector<int>> dp(Row + 1, vector<int>(Col + 1, 0));

    int result = 0;
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            // If elements is at top row or first
            // column, it wont form a  square
            // matrix's bottom-right
            if (i == 0 || j == 0)
                dp[i][j] = 1;

            // Check if adjacent elements are equal
            else if (a[i][j] == a[i - 1][j] && a[i][j] == a[i][j - 1] && a[i][j] == a[i - 1][j - 1])
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});

            // If not equal, then it will form a 1x1
            // submatrix
            else
                dp[i][j] = 1;

            // Update result at each (i,j)
            result = max(result, dp[i][j]);
        }
    }

    return result;
}