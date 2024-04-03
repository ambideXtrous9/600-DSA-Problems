#include <bits/stdc++.h>

using namespace std;

int maxSumIS(int arr[], int n)
{
    vector<int> dp(n,0);

    int res = INT_MIN;
    
    for (int cur = 0; cur < n; cur++)
    {
        dp[cur] = arr[cur];
        for (int prev = 0; prev < cur; prev++)
        {
            if (arr[cur] > arr[prev])
            {
                dp[cur] = max(dp[cur], dp[prev] + arr[cur]);
            }
        }
        res = max(res, dp[cur]);
    }

    return res;
}


int maxSumIS(int arr[], int n)
{
    vector<int> dp(arr,arr+n);
    int res = INT_MIN;
    for (int cur = 0; cur < n; cur++)
    {
        for (int prev = 0; prev < cur; prev++)
        {
            if (arr[cur] > arr[prev])
            {
                dp[cur] = max(dp[cur], dp[prev] + arr[cur]);
            }
        }
        res = max(res, dp[cur]);
    }

    return res;
}