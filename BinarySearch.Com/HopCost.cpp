#include <bits/stdc++.h>

using namespace std;

int dp[1001][3];

int HC(vector<int> &nums0, vector<int> &nums1, int dist, int cost, int i, int n, int turn)
{

    if (i == n - 1 && turn == 0)
        return nums0[i];

    if (i == n - 1 && turn == 1)
        return nums1[i];

    if (dp[i][turn] != -1)
        return dp[i][turn];

    int d = INT_MAX;

    for (int t = 1; t <= dist; t++)
    {
        if (i + t < n)
        {

            if (turn == 0)
            {
                d = min(d, nums0[i] + HC(nums0, nums1, dist, cost, i + t, n, turn));

                d = min(d, nums0[i] + cost + HC(nums0, nums1, dist, cost, i + t, n, !turn));
            }
            if (turn == 1)
            {
                d = min(d, nums1[i] + HC(nums0, nums1, dist, cost, i + t, n, turn));

                d = min(d, nums1[i] + cost + HC(nums0, nums1, dist, cost, i + t, n, !turn));
            }
        }
    }

    return dp[i][turn] = d;
}

int solve(vector<int> &nums0, vector<int> &nums1, int dist, int cost)
{

    int n = nums0.size();

    memset(dp, -1, sizeof(dp));

    int X = min(HC(nums0, nums1, dist, cost, 0, n, 0), HC(nums0, nums1, dist, cost, 0, n, 1));

    if (X == INT_MAX)
        return 0;
    return X;
}