#include <bits/stdc++.h>

using namespace std;

int LIS(int cur, int prev, int n, vector<int> &arr)
{
    if (cur == n) return 0;

    int len = LIS(cur + 1, prev, n, arr); // not taken

    if (prev == -1 || arr[cur] > arr[prev]) // take only when this cond true
    {
        len = max(len, 1 + LIS(cur + 1, cur, n, arr));
    }

    return len;
}

int LISUtil(vector<int> &arr)
{
    return LIS(0, -1, arr.size(), arr);
}

int LIS(int cur, int prev, int n, vector<int> &arr, vector<vector<int>> &dp)
{
    if (cur == n) return 0;

    if (dp[cur][prev + 1] != -1)
        return dp[cur][prev + 1]; // coordinate shift

    int len = LIS(cur + 1, prev, n, arr, dp); // not taken

    if (prev == -1 || arr[cur] > arr[prev]) // take condition
    {
        len = max(len, 1 + LIS(cur + 1, cur, n, arr, dp));
    }

    return dp[cur][prev + 1] = len; // coordinate shift
}

int LISUtil(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return LIS(0, -1, n, arr, dp);
}

int LIS(int n, vector<int> &arr, vector<vector<int>> &dp)
{
    for (int cur = n - 1; cur >= 0; cur--)
    {
        for (int prev = cur; prev >= -1; prev--)
        {
            int len = 0 + dp[cur + 1][prev + 1]; // not taken //coordinate shift

            if (prev == -1 || arr[cur] > arr[prev])
            {
                len = max(len, 1 + dp[cur + 1][cur + 1]); // coordinate shift
            }

            dp[cur][prev + 1] = len;
        }
    }

    return dp[0][-1 + 1];
}

int LISUtil(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    return LIS(n, arr, dp);
}

int LIS(int n, vector<int> &arr)
{
    vector<int> previous(n + 1, 0);
    vector<int> current(n + 1, 0);

    for (int cur = n - 1; cur >= 0; cur--)
    {
        for (int prev = cur; prev >= -1; prev--)
        {
            int len = 0 + previous[prev + 1]; // not taken //coordinate shift

            if (prev == -1 || arr[cur] > arr[prev])
            {
                len = max(len, 1 + previous[cur + 1]); // coordinate shift
            }

            current[prev + 1] = len;
        }
        previous = current;
    }

    return previous[-1 + 1];
}

int LISUtil(vector<int> &arr)
{
    int n = arr.size();
    return LIS(n, arr);
}

int LIS(int n, vector<int> &arr)
{
    vector<int> dp(n + 1, 1);
    
    int res = INT_MIN;
    
    for (int cur = 0; cur < n; cur++)
    {
        for (int prev = 0; prev < cur; prev++)
        {
            if (arr[cur] > arr[prev])
            {
                dp[cur] = max(dp[cur], dp[prev] + 1);
            }
        }
        res = max(res, dp[cur]);
    }

    return res;
}

int LISUtil(vector<int> &arr)
{
    int n = arr.size();
    return LIS(n, arr);
}

int LIS(int n, vector<int> &arr)
{
    vector<int> res;
    res.push_back(arr[0]);
    for (int cur = 1; cur < n; cur++)
    {
        if (arr[cur] > res.back())
        {
            res.push_back(arr[cur]);
        }
        else
        {
            int idx = lower_bound(res.begin(), res.end(), arr[cur]) - res.begin();

            res[idx] = arr[cur];
        }
    }

    return res.size();
}

int LISUtil(int arr[], int n)
{
    vector<int> a(arr, arr + n);
    return LIS(n, a);
}

//----------------- LIS at each idx---------------------------

int LISS(vector<int> arr,int n)
{
    vector<int> LIS(n,1);

    if(n==0) return 0;

    int ans = 0;

    for(int i = 0;i<n;i++)
    {
        LIS[i] = 1;
        
        for(int j = 0;j<i;j++)
        {
            if(arr[i]>arr[j] && LIS[i] < LIS[j] + 1)
            {
                LIS[i] = LIS[j]+1;
            }
        }

        ans = max(ans,LIS[i]);
    }

    return ans;
}
