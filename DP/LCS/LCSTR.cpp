#include <bits/stdc++.h>

using namespace std;

int f(int i, int j, string &S1, string &S2, vector<vector<int>> &dp, int &ans)
{
    int take = 0, nottake1 = 0, nottake2 = 0;
    
    if (i < 0 || j < 0)
        return 0;
    
    if (dp[i][j] != -1)
        return dp[i][j];
    
    if (S1[i] == S2[j])
        take = 1 + f(i - 1, j - 1, S1, S2, dp, ans);
    
    nottake1 = f(i - 1, j, S1, S2, dp, ans);
    
    nottake2 = f(i, j - 1, S1, S2, dp, ans);
    
    ans = max(ans, take);
    
    return dp[i][j] = take;
}

int longestCommonSubstr(string S1, string S2, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int ans = 0;
    f(n - 1, m - 1, S1, S2, dp, ans);
    return ans;
}

int LCSTR(string S1, string S2, int n, int m, int count)
{
    if (n == 0 || m == 0)
        return count;

    int cnt1 = count;

    if (S1[n - 1] == S2[m - 1])
        cnt1 = LCSTR(S1, S2, n - 1, m - 1, count + 1);

    int cnt2 = LCSTR(S1, S2, n, m - 1, 0);

    int cnt3 = LCSTR(S1, S2, n - 1, m, 0);

    return max(cnt1, max(cnt2, cnt3));
}

int LCSTR(string S1, string S2, int n, int m, int count, vector<vector<vector<int>>> &dp)
{
    if (n == 0 || m == 0)
        return count;

    if (dp[n][m][count] != -1)
        return dp[n][m][count];

    int cnt1 = count;

    if (S1[n - 1] == S2[m - 1])
        cnt1 = LCSTR(S1, S2, n - 1, m - 1, count + 1, dp);

    int cnt2 = LCSTR(S1, S2, n, m - 1, 0, dp);

    int cnt3 = LCSTR(S1, S2, n - 1, m, 0, dp);

    return dp[n][m][count] = max(cnt1, max(cnt2, cnt3));
}

int longestCommonSubstr(string S1, string S2, int n, int m)
{
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

    return LCSTR(S1, S2, n, m, 0, dp);
}

int LCSTR(string S1, string S2, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int result = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (S1[i - 1] == S2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = 0;
            }

            result = max(result, dp[i][j]);
        }
    }
    return result;
}
int longestCommonSubstr(string S1, string S2, int n, int m)
{
    return LCSTR(S1, S2, n, m);
}

int LCSTR(string S1, string S2, int n, int m)
{
    int x = min(m, n);

    vector<int> prev(m + 1, 0);
    vector<int> cur(m + 1, 0);

    int result = 0;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                cur[j] = 0;
            }
            else if (S1[i - 1] == S2[j - 1])
            {
                cur[j] = prev[j - 1] + 1;
                result = max(result, cur[j]);
            }
            else
            {
                cur[j] = 0;
            }
        }
        prev = cur;
    }
    return result;
}
int longestCommonSubstr(string S1, string S2, int n, int m)
{
    return LCSTR(S1, S2, n, m);
}