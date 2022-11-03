#include <bits/stdc++.h>

using namespace std;

// LC 1696. Jump Game VI

int cost(vector<int> &nums, int i, int n, int k, vector<int> &dp)
{
    if (i == n - 1)
        return nums[i];

    if (i >= n)
        return 1e9;

    if (dp[i] != -1)
        return dp[i];

    int cos = 1e9;

    for (int j = 1; j <= k; j++)
    {
        cos = min(cos, nums[i] + cost(nums, i + j, n, k, dp));
    }

    return dp[i] = cos;
}

int solve(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> dp(n, INT_MAX);

    dp[0] = nums[0];

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i + j < n && dp[i] != INT_MAX)
            {
                dp[i + j] = min(dp[i + j], dp[i] + nums[i + j]);
            }
        }
    }

    return dp[n - 1];
}

int solve(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> dp(n + 1, -1);
    return cost(nums, 0, n, k, dp);
}

/*
1. score[i] will store the score if I start jumping from index i and reach n-1. 
2. priority queue(MINHEAP) will store all the scores of the window [i+1, min(n-1, i+k)].
3. To get the min score from index i, I should jump to next index with the min value in the window.
*/
#define pii pair<int, int>
int solve(vector<int> &nums, int k)
{
    int n = nums.size();
    int score[n];
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for (int i = n - 1; i >= 0; i--)
    {
        while (pq.size() && pq.top().second > i + k)
            pq.pop();

        score[i] = nums[i];

        score[i] += (pq.size() ? pq.top().first : 0);

        pq.push({score[i], i});
    }

    return score[0];
}



int maxResult(vector<int> &nums, int k)
{
    int sum = 0;

    priority_queue<pii, vector<pii>, greater<pii>> H; // min-heap for min dist upto idx i

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        while (!H.empty() && H.top().second > i + k) // i + k denotes current at i, max we can reach taking k steps
        {
            H.pop();
        }

        sum = H.empty() ? nums[i] : nums[i] + H.top().first;

        H.push({sum, i});
    }

    return sum;
}