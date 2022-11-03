#include <bits/stdc++.h>
using namespace std;

bool check(char &c1, char &c2)
{
    if (c1 == c2)
    {
        return true;
    }
    if (c1 == 'a' && c2 == 'o')
    {
        return true;
    }
    if (c1 == 'o' && c2 == 'a')
    {
        return true;
    }
    if (c1 == 't' && c2 == 'l')
    {
        return true;
    }
    if (c1 == 'l' && c2 == 't')
    {
        return true;
    }
    return false;
}

bool f(string drawString, string ticket, int i, int j, int k, int flag, vector<vector<vector<vector<int>>>> &dp)
{
    if (j < 0)
        return true;
    if (i < 0)
        return false;

    if (dp[i][j][k][flag] != -1)
        return dp[i][j][k][flag];

    bool ans = false;

    if (check(drawString[i],ticket[j]))
    {
        ans = ans || f(drawString, ticket, i - 1, j - 1, k, 1, dp);
    }
    else if (k > 0 && flag)
    {
        ans = ans || f(drawString, ticket, i - 1, j, k - 1, 1, dp);
    }
    else if (flag)
    {
        ans = ans || f(drawString, ticket, i, j - 1, k, 1, dp);
    }

    if (!flag && drawString.length() >= ticket.length())
    {
        ans = ans || f(drawString, ticket, i - 1, j, k, 0, dp);
    }
    else
    {
        ans = ans || f(drawString, ticket, i, j - 1, k, 0, dp);
    }

    return dp[i][j][k][flag] = ans;
}

int main()
{
    int n;
    cin >> n;

    vector<string> tickets(n);
    for (int i = 0; i < n; i++)
    {
        cin >> tickets[i];
    }

    string drawString;
    cin >> drawString;

    int k;
    cin >> k;

    int ans = 0;
    int m = drawString.length();

    for (auto it : tickets)
    {
        int n = it.length();
        vector<vector<vector<vector<int>>>> dp(m, vector<vector<vector<int>>>(n, vector<vector<int>>(k + 1, vector<int>(2, -1))));
        if (f(drawString, it, m - 1, n - 1, k, 0, dp))
            ans++;
    }

    cout << ans << endl;

    return 0;
}