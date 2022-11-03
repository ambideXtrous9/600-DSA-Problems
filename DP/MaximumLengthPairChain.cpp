#include <bits/stdc++.h>

using namespace std;

int findLongestChain(vector<vector<int>> &arr)
{
    int n = arr.size();
    
    sort(arr.begin(), arr.end());

    vector<int> dp(n + 1, 1);
    
    int res = INT_MIN;
    
    for (int cur = 0; cur < n; cur++)
    {
        for (int prev = 0; prev < cur; prev++)
        {
            if (arr[cur][0] > arr[prev][1])
            {
                dp[cur] = max(dp[cur], dp[prev] + 1);
            }
        }
        res = max(res, dp[cur]);
    }
    return res;
}