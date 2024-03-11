#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];

int func(int price[], int arr[], int n, int w)
{
    if (n == 0 || w == 0)
        return 0;

    if (dp[n][w] != -1)
        return dp[n][w];

    if (arr[n - 1] <= w)
        return dp[n][w] = max(price[n - 1] + func(price, arr, n, w - arr[n - 1]), func(price, arr, n - 1, w));

    else
        return dp[n][w] = func(price, arr, n - 1, w);
}

int cutRod(int price[], int n)
{
    int arr[n];

    // equivalent to weight array in KS
    for (int i = 0; i < n; i++) // storing len of rods of every possible cut
        arr[i] = i + 1;

    memset(dp, -1, sizeof(dp));

    return func(price, arr, n, n);

    // code here
}