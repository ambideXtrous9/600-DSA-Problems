#include <bits/stdc++.h>

using namespace std;

int MINJ(int arr[], int i, int n, vector<int> &dp)
{
    if (i >= n - 1)
        return 0;

    if (arr[i] == 0)
        return INT_MAX;

    if (dp[i] != -1)
        return dp[i];

    int res = INT_MAX;

    for (int k = 1; k <= arr[i]; k++)
    {
        int jumps = 0;

        jumps = MINJ(arr, i + k, n, dp);

        if (jumps != INT_MAX)
            res = min(res, jumps + 1);
    }

    return dp[i] = res;
}

int minJumps(int arr[], int n)
{
    vector<int> dp(n + 1, -1);
    int ans = MINJ(arr, 0, n, dp);
    return (ans == INT_MAX) ? -1 : ans;
}