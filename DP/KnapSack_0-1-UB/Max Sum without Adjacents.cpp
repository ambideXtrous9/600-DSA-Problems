#include <bits/stdc++.h>

using namespace std;

// House Robber

int KS(int *arr, int n, vector<int> &dp)
{
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int take = arr[n - 1] + KS(arr, n - 2, dp);

    int nottake = KS(arr, n - 1, dp);

    dp[n] = max(take, nottake);
}

int findMaxSum(int *arr, int n)
{

    vector<int> dp(n + 1, -1);
    return KS(arr, n, dp);
    // code here
}

int KS(int *arr, int n, bool flag, vector<vector<int>> &dp)
{
    if (n == 0)
        return 0;

    if (dp[n][flag] != -1)
        return dp[n][flag];

    if (flag)
        return dp[n][flag] = max(arr[n - 1] + KS(arr, n - 1, !flag, dp), KS(arr, n - 1, flag, dp));

    else
        return dp[n][flag] = KS(arr, n - 1, !flag, dp);
}

int findMaxSum(int *arr, int n)
{

    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    return KS(arr, n, true, dp);
    // code here
}