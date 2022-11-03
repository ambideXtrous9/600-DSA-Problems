#include <bits/stdc++.h>

using namespace std;

struct val
{
    int first;
    int second;
};

bool comp(struct val v1, struct val v2)
{
    return v1.first < v2.first;
}

int LIS(int n, struct val arr[])
{
    vector<int> dp(n + 1, 1);
    
    int res = INT_MIN;
    
    for (int cur = 0; cur < n; cur++)
    {
        for (int prev = 0; prev < cur; prev++)
        {
            if (arr[cur].first > arr[prev].second)
            {
                dp[cur] = max(dp[cur], dp[prev] + 1);
            }
        }
        res = max(res, dp[cur]);
    }

    return res;
}

int maxChainLen(struct val p[], int n)
{
    sort(p, p + n, comp);

    return LIS(n, p);
}