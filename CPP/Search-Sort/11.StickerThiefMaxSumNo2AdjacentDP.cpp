#include <bits/stdc++.h>

using namespace std;

int solve(int i, int arr[], vector<int> &dp)
{
    if (i < 0)
    {
        return 0;
    }
    if (dp[i] != -1)
        return dp[i];
    int inc = arr[i - 1] + solve(i - 2, arr, dp);
    int exc = solve(i - 1, arr, dp);
    return dp[i] = max(inc, exc);
}
int FindMaxSum(int arr[], int n)
{
    // Your code here
    vector<int> dp(n + 1, -1);
    return solve(n, arr, dp);
}