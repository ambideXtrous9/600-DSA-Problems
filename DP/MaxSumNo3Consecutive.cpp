#include <bits/stdc++.h>

using namespace std;

int dp[10001];

int fsum(vector<int> &a, int n)
{
    if (n <= 0)
        return 0;

    if(n==1) return a[n-1];

    if (dp[n] != -1)
        return dp[n];

    int x = fsum(a, n - 1);
    int y = a[n - 1] + fsum(a, n - 2);
    int z = a[n - 1] + a[n - 2] + fsum(a, n - 3);

    return dp[n] = max({x, y, z});
}

int maxSum(vector<int> &a, int n)
{
    memset(dp, -1, sizeof(dp));

    return fsum(a, n);
}

int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int sum[10000];

int maxSumWO3Consec(int n)
{
    if (n <= 0)
        return 0;

    if (n == 1)
        return arr[0];

    if (n == 2)
        return arr[1] + arr[0];

    if (sum[n] != -1)
        return sum[n];

    int excl1 = maxSumWO3Consec(n - 1);
    int excl2 = arr[n - 1] + maxSumWO3Consec(n - 2);
    int excl3 = arr[n - 1] + arr[n - 2] + maxSumWO3Consec(n - 3);

    return sum[n] = max(max(excl2, excl3), excl1);
}

int maxSumWO3Consec(int n)
{
    vector<int> dp(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
            dp[i] = 0;
        else if (i == 1)
            dp[i] = arr[0];
        else if (i == 2)
            dp[i] = arr[1] + arr[0];
        else
        {
            int excl1 = dp[i - 1];
            int excl2 = INT_MIN;
            if (i - 2 >= 0)
                excl2 = arr[i - 1] + dp[i - 2];
            int excl3 = INT_MIN;
            if (i - 3 >= 0)
                excl3 = arr[i - 1] + arr[i - 2] + dp[i - 3];
            dp[i] = max(max(excl2, excl3), excl1);
        }
    }
    return dp[n];
}

// Driver code
int main()
{
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSumWO3Consec(n);
    return 0;
}