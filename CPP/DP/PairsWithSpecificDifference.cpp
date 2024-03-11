#include <bits/stdc++.h>

using namespace std;

int f(int i, int j, int arr[], int N, int K, vector<vector<int>> &dp)
{
    int take = 0, nottake = 0;
    
    if (j < 0)
        return 0;
    
    if (dp[i][j] != -1)
        return dp[i][j];

    if (arr[i] - arr[j] < K)
        take = arr[i] + arr[j] + f(j - 1, j - 2, arr, N, K, dp);

    nottake = f(i - 1, j - 1, arr, N, K, dp);

    return dp[i][j] = max(take, nottake);
}
int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
{
    // Your code goes here
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
    sort(arr, arr + N);
    return f(N - 1, N - 2, arr, N, K, dp);
}

int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int maxsum = 0;

    for (int i = n - 1; i > 0; i--)
    {
        if (arr[i] - arr[i - 1] < k)
        {
            maxsum += arr[i] + arr[i - 1];
            i--;
        }
    }
    return maxsum;
}