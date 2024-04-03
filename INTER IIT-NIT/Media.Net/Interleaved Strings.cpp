#include <bits/stdc++.h>

using namespace std;

bool solve(string A, string B, string C, int n, int m, int len, vector<vector<int>> &dp)
{
    if (len == 0)
    {
        return true;
    }
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }

    int a=0, b=0;

    if (n - 1 >= 0 && A[n - 1] == C[len - 1])
        a = solve(A, B, C, n - 1, m, len - 1, dp);

    if (m - 1 >= 0 && B[m - 1] == C[len - 1])
        b = solve(A, B, C, n, m - 1, len - 1, dp);
    
    return dp[n][m] = a || b;
}
bool isInterleave(string A, string B, string C)
{
    // Your code here
    int n = A.length();
    int m = B.length();
    int len = C.length();

    if (len != n + m) return false;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    return solve(A, B, C, n, m, len, dp);
}