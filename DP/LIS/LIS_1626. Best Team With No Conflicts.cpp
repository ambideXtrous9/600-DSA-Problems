#include <bits/stdc++.h>

using namespace std;

int LIS(vector<vector<int>> &V, int cur, int prev, int n, vector<vector<int>> &dp)
{
    if (cur == n)
        return 0;

    if (dp[cur][prev + 1] != -1)
        return dp[cur][prev + 1];

    int nt = LIS(V, cur + 1, prev, n, dp);

    if (prev == -1 || V[cur][1] >= V[prev][1])
    {
        nt = max(nt, V[cur][1] + LIS(V, cur + 1, cur, n, dp));
    }

    return dp[cur][prev + 1] = nt;
}

int bestTeamScore(vector<int> &scores, vector<int> &ages)
{

    vector<vector<int>> V;

    int n = ages.size();

    for (int i = 0; i < ages.size(); i++)
    {
        V.push_back({ages[i], scores[i]});
    }

    sort(V.begin(), V.end());

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    return LIS(V, 0, -1, n, dp);
}

int bestTeamScore(vector<int> &scores, vector<int> &ages)
{

    vector<vector<int>> V;

    int n = ages.size();

    for (int i = 0; i < ages.size(); i++)
    {
        V.push_back({ages[i], scores[i]});
    }

    sort(V.begin(), V.end());

    vector<int> dp(n, 0);

    int res = INT_MIN;

    for (int cur = 0; cur < n; cur++)
    {
        dp[cur] = V[cur][1];
        for (int prev = 0; prev < cur; prev++)
        {
            if (V[cur][1] >= V[prev][1])
            {
                dp[cur] = max(dp[cur], dp[prev] + V[cur][1]);
            }
        }
        res = max(res, dp[cur]);
    }

    return res;
}