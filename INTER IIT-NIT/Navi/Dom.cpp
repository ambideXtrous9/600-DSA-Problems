#include <bits/stdc++.h>

using namespace std;


int f(int i, int p, int mx, int n, int k, vector<int> &a, vector<vector<int>> &dp)
{
    if (p == k)
        return mx;

    int remaining = (n - i) >> 1;

    if (p + remaining < k)
        return 1e9;

    if (i >= n - 1)
        return 1e9;

    if (dp[i][p] != -1)
        return dp[i][p];
    // we can take or not

    int ans = f(i + 1, p, mx, n, k, a, dp);
    
    ans = min(ans, f(i + 2, p + 1, max(mx, a[i + 1] - a[i]), n, k, a, dp));

    return dp[i][p] = ans;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a.begin(), a.end());

    vector<vector<int>> dp(n, vector<int>(k, -1));

    cout << f(0, 0, 0, n, k, a, dp);
}