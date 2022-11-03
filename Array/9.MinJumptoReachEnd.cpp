#include <bits/stdc++.h>

using namespace std;

int minJumps(int arr[], int n)
{
    // Your code here
    int farthest = 0; 
    int jumps = 0; 
    int current = 0;

    for (int i = 0; i < n - 1; i++)
    {
        farthest = max(farthest, i + arr[i]);
        
        if (i == current)
        {
            jumps++;
            current = farthest;
        }
    }
    if (current < n - 1)
        return -1;
    return jumps;
}

int MINJ(int arr[],int i,int n,vector<int> &dp)
{
    
    if (i >= n-1) return 0;
    
    if (arr[i] == 0) return 1e9;

    if(dp[i]!=-1) return dp[i];

    int res = 1e9;

    for (int k = 1; k <= arr[i]; k++)
    {
        res = min(res,1 + MINJ(arr, i+k,n,dp));

    }

    return dp[i] = res;
}

int minJumps(int arr[], int n)
{
    vector<int> dp(n+1,-1);
    int ans =  MINJ(arr,0,n,dp);
    return (ans>=1e9) ? -1 : ans;
}

// Similar to Frog k jump 1D-DP

int minJumps(int arr[], int n)
{
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= arr[i]; j++)
        {
            if (i + j < n && dp[i] != INT_MAX)
            {
                dp[i + j] = min(dp[i + j], dp[i] + 1);
            }
        }
    }
    if (dp[n - 1] == INT_MAX)
        return -1;
    return dp[n - 1];
}

int minJumps(int arr[], int n)
{
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] + j >= i && dp[j] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    if (dp[n - 1] == INT_MAX)
        return -1;
    return dp[n - 1];
}


/*
1. score[i] will store the score if I start jumping from index i and reach n-1. 
2. priority queue(MINHEAP) will store all the scores of the window [i+1, min(n-1, i+k)].
3. To get the min score from index i, I should jump to next index with the min value in the window.
*/
#define pii pair<int, int>
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