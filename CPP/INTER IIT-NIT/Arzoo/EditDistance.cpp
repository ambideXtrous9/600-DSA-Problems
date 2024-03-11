#include <bits/stdc++.h>

using namespace std;

int ED(string s, string t, int n, int m)
{
    if (n == 0)
        return m;
    if (m == 0)
        return n;

    if (s[n - 1] == t[m - 1])
        return ED(s, t, n - 1, m - 1);

    return 1 + min(ED(s, t, n - 1, m - 1), min(ED(s, t, n, m - 1), ED(s, t, n - 1, m)));
}

int editDistance(string s, string t)
{

    int n = s.length();
    int m = t.length();

    return ED(s, t, n, m);
}

int ED(string s, string t, int n, int m, vector<vector<int>> &dp)
{
    if (n == 0)
        return m;
    if (m == 0)
        return n;

    if (dp[n][m] != -1)
        return dp[n][m];

    if (s[n - 1] == t[m - 1])
        return dp[n][m] = ED(s, t, n - 1, m - 1, dp);

    return dp[n][m] = 1 + min(ED(s, t, n - 1, m - 1, dp), min(ED(s, t, n, m - 1, dp), ED(s, t, n - 1, m, dp)));
}

int ED(string s, string t, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= m; i++) // when n == 0 ret m
        dp[0][i] = i;
    for (int i = 0; i <= n; i++)  // when m==0 ret n
        dp[i][0] = i;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
            }
        }
    }

    return dp[n][m];
}

int editDistance(string s, string t)
{
    int n = s.length();
    int m = t.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    return ED(s, t, n, m, dp);
}