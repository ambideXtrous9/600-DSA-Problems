#include <bits/stdc++.h>
using namespace std;

// Function to count numbers of such subsequences
// having product less than k.

int productSubSeqCount(vector<int> &arr, int k, int n)
{
    if (n == 0)
        return 0;
    if (k == 0)
        return 0;

    int excl = productSubSeqCount(arr, k, n - 1);

    if (arr[n - 1] <= k)
    {
        excl += 1 + productSubSeqCount(arr, k / arr[n - 1], n - 1);
    }

    return excl;
}

int productSubSeqCount(vector<int> &arr, int k, int n, vector<vector<int>> &dp)
{
    if (n == 0)
        return 0;
    if (k == 0)
        return 0;

    if (dp[k][n] != -1)
        return dp[k][n];

    int excl = productSubSeqCount(arr, k, n - 1);

    if (arr[n - 1] <= k)
    {
        excl += 1 + productSubSeqCount(arr, k / arr[n - 1], n - 1);
    }

    return dp[k][n] = excl;
}

int productSubSeqCount(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            else if (j == 0)
                dp[i][j] = 0;
            else
            {
                int excl = dp[i - 1][j];

                if (arr[i - 1] <= j)
                {
                    excl += 1 + dp[i - 1][j / arr[i - 1]];
                }
                dp[i][j] = excl;
            }
        }
    }
    return dp[n][k];
}
