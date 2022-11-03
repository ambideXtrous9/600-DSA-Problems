#include <bits/stdc++.h>

using namespace std;

string shortestCommonSupersequence(string s, string t)
{
    int n = s.length();
    int m = t.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int i = n;
    int j = m;

    string str = "";

    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            str.push_back(s[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            str.push_back(s[i - 1]);
            i--;
        }
        else
        {
            str.push_back(t[j - 1]);
            j--;
        }
    }

    while (i > 0)
    {
        str.push_back(s[i - 1]);
        i--;
    }
    while (j > 0)
    {
        str.push_back(t[j - 1]);
        j--;
    }

    reverse(str.begin(), str.end());

    return str;
}