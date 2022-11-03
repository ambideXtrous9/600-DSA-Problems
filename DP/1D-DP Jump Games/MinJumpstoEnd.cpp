#include <bits/stdc++.h>

using namespace std;

int MINJ(int arr[], int l, int h)
{
    if (h == l)
        return 0;

    if (arr[l] == 0)
        return INT_MAX;

    int res = INT_MAX;

    for (int i = 1; i <= arr[l]; i++)
    {
        int jumps = 0;

        if (i + l <= h) jumps = MINJ(arr, l + i, h);

        if (jumps != INT_MAX) res = min(res, jumps + 1);
    }
    
    return res;
}

int minJumps(int arr[], int n)
{
    vector<int> dp(n + 1, -1);
    return MINJ(arr, 0, n - 1);
}
int MINJ(int arr[], int l, int h, vector<int> &dp)
{
    if (h == l)
        return 0;

    if (arr[l] == 0)
        return INT_MAX;

    if (dp[l] != -1)
        return dp[l];

    int res = INT_MAX;

    for (int i = 1; i <= arr[l]; i++)
    {
        int jumps = 0;

        if (l + i <= h)
            jumps = MINJ(arr, l + i, h, dp);

        if (jumps != INT_MAX)
            res = min(res, jumps + 1);
    }

    return dp[l] = res;
}

int minJumps(int arr[], int n)
{
    vector<int> dp(n + 1, -1);
    int ans = MINJ(arr, 0, n - 1, dp);

    return (ans == INT_MAX) ? -1 : ans;
}

int minJumps(int arr[], int n)
{
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= arr[i]; j++)
        {
            if (i + j < n && dp[i] != INT_MAX)
            {

                dp[i + j] = min(dp[i + j], dp[i] + 1);
            }
        }
    }
    if (dp[n - 1] == INT_MAX)
        return -1;
    return dp[n - 1];
}

int minJumps(int arr[], int n)
{
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] + j >= i && dp[j] != INT_MAX)
            {

                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    if (dp[n - 1] == INT_MAX)
        return -1;
    return dp[n - 1];
}

int minJumps(int arr[], int n)
{
    // Your code here
    int farthest = 0, jumps = 0, current = 0;
    for (int i = 0; i < n - 1; i++)
    {
        farthest = max(farthest, i + arr[i]);
        if (i == current)
        {
            jumps++;
            current = farthest;
        }
    }
    if (current < n - 1)
        return -1;
    return jumps;
}
