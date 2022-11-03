#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];

int LRS(string S1, string S2, int n, int m)
{
    if (n == 0 || m == 0)
        return 0;

    if (dp[n][m] != -1)
        return dp[n][m];

    if (S1[n - 1] == S2[m - 1] && n != m)
        return dp[n][m] = 1 + LRS(S1, S2, n - 1, m - 1);

    return dp[n][m] = max(LRS(S1, S2, n, m - 1), LRS(S1, S2, n - 1, m));
}

int LongestRepeatingSubsequence(string str)
{
    int n = str.length();

    memset(dp, -1, sizeof(dp));

    return LRS(str, str, n, n);
}

int LCS_SO(int x, int y, string s1, string s2)
{
    vector<int> prev(y + 1, 0);

    for (int i = 1; i <= x; i++)
    {
        vector<int> cur(y + 1, 0);
        for (int j = 1; j <= y; j++)
        {
            if (s1[i - 1] == s2[j - 1] && i != j)
                cur[j] = 1 + prev[j - 1];
            else
                cur[j] = max(prev[j], cur[j - 1]);
        }
        prev = cur;
    }

    return prev[y];
}
int LongestRepeatingSubsequence(string str)
{
    int n = str.length();
    return LCS_SO(n, n, str, str);
    // Code here
}