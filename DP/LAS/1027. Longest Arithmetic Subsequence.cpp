#include <bits/stdc++.h>

using namespace std;

// dp[i][d] -> length of the AP with upto ith index with cd = d.

int longestArithSeqLength(vector<int> &nums)
{
    int n = nums.size();
    int ans = 0;

    if (n <= 2)
        return n;

    vector<vector<int>> dp(n, vector<int>(1501, 0)); // based on constraints

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int d = nums[j] - nums[i] + 1000; // coordinate shift avoid negative index

            dp[j][d] = max(dp[i][d] + 1, 2);

            ans = max(ans, dp[j][d]);
        }
    }

    return ans;
}

// using 2D map.

int longestArithSeqLength(vector<int> &A)
{
    unordered_map<int, unordered_map<int, int>> dp;

    int n = A.size();
    int res = 2;

    if (n <= 2)
        return n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int d = A[j] - A[i];

            dp[d][j] = dp[d].count(i) ? dp[d][i] + 1 : 2;

            res = max(res, dp[d][j]);
        }
    }
    return res;
}

// 1218. Longest Arithmetic Subsequence of Given Difference

int longestSubsequence(vector<int> &arr, int diff)
{
    unordered_map<int, int> mp;
    int ans = 1;
    
    for (int i = 0; i < arr.size(); i++)
    {
        // when element found in map with given CD, 
        // then increment the count upto that element
        // and store the max
        if (mp.find(arr[i] - diff) != mp.end()) 
        {
            int curr = mp[arr[i] - diff] + 1;
    
            mp[arr[i]] = curr;
    
            ans = max(ans, curr);
        }
        else
        {
            mp[arr[i]] = 1;
        }
    }
    return ans;
}