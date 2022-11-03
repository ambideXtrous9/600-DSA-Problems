#include <bits/stdc++.h>

using namespace std;

int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

    for (auto x : edges)
    {
        dp[x[0]][x[1]] = x[2];
        dp[x[1]][x[0]] = x[2];
    }

    for (int i = 0; i < n; i++)
        dp[i][i] = 0;

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dp[i][k] != INT_MAX && dp[k][j] != INT_MAX && dp[i][j] > dp[i][k] + dp[k][j])
                {
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }

    int node = -1;
    int cnt = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (i != j && dp[i][j] <= distanceThreshold)
            {
                count++;
            }
        }

        cout << i << "-> " << count << endl;

        if (count <= cnt)
        {
            cnt = count;
            node = max(node, i);
        }
    }

    return node;
}