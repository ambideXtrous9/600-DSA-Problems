#include <bits/stdc++.h>

using namespace std;

#define MAX 100
int dp[MAX][MAX];

int countRemovals(vector<int> &a, int i, int j, int k)
{
    if (i >= j)
        return 0;

    else if ((a[j] - a[i]) <= k)
        return 0;

    else if (dp[i][j] != -1)
        return dp[i][j];

    else if ((a[j] - a[i]) > k)
    {

        dp[i][j] = 1 + min(countRemovals(a, i + 1, j, k),
                           countRemovals(a, i, j - 1, k));
    }
    return dp[i][j];
}
int removals(vector<int> &a, int k)
{

    int n = a.size();
    sort(a.begin(), a.end());

    // fill all stated with -1
    // when only one element
    memset(dp, -1, sizeof(dp));
    if (n == 1)
        return 0;
    else
        return countRemovals(a, 0, n - 1, k);
}