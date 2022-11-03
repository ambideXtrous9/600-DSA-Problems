#include <bits/stdc++.h>

using namespace std;

// 1.MEMOIZATION

int dp[21][21][21];
int solve(string &a, string &b, string &c, int i, int j, int k)
{
    if (i < 0 || j < 0 || k < 0)
    {
        return 0;
    }
    if (dp[i][j][k] != -1)
    {
        return dp[i][j][k];
    }
    if ((a[i] == b[j]) && (a[i] == c[k]))
    {
        dp[i][j][k] = 1 + solve(a, b, c, i - 1, j - 1, k - 1);
    }
    else
    {
        dp[i][j][k] = max(solve(a, b, c, i - 1, j, k), max(solve(a, b, c, i, j - 1, k), solve(a, b, c, i, j, k - 1)));
    }
    return dp[i][j][k];
}
int LCSof3(string A, string B, string C, int n1, int n2, int n3)
{
    memset(dp, -1, sizeof(dp));
    return solve(A, B, C, n1 - 1, n2 - 1, n3 - 1);
}

// 2. TABULATION

int LCSof3(string A, string B, string C, int n1, int n2, int n3)
{
    int L[n1 + 1][n2 + 1][n3 + 1];

    for (int i = 0; i <= n1; i++)
    {
        for (int j = 0; j <= n2; j++)
        {
            for (int k = 0; k <= n3; k++)
            {
                if (i == 0 || j == 0 || k == 0)
                    L[i][j][k] = 0;

                else if (A[i - 1] == B[j - 1] && A[i - 1] == C[k - 1])
                    L[i][j][k] = L[i - 1][j - 1][k - 1] + 1;

                else
                    L[i][j][k] = max(max(L[i - 1][j][k],L[i][j - 1][k]),L[i][j][k - 1]);
            }
        }
    }

    return L[n1][n2][n3];
}