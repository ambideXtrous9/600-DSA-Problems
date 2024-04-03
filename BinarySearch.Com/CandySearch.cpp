#include <bits/stdc++.h>

using namespace std;

int dp1[100005][2];
int f(int i,int n,vector<int> &nums, int player)
{
    if (i >= n)
        return 0;
    if (i <= 0)
        return 0;

    if (dp1[i][player] != -1)
        return dp1[i][player];
    int ans = 0;

    if (player == 0) // player 1 tries to max his score
    {
        ans = max(ans, nums[i] + f(i + 1, n,nums, 1));

        
        ans = max(ans, nums[n-1] + f(i, n-1,nums, 1));
    }
    else
    {
        // player is 2
        ans = INT_MAX;
        ans = min(ans, min(f(i + 1, n,nums, 0), f(i, n-1,nums, 0)));
    }
    return dp1[i][player] = ans;
}
bool solve(vector<int> &nums)
{
    int n = nums.size();
    
    int sum = 0, ans = 0;
    
    memset(dp1, -1, sizeof(dp1));
    
    ans = f(0,n,nums, 0);
    
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    return ans > (sum / 2);
}

int dp[1001][1001];
int solve(int i, int j, vector<int> a)
{

    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    

    int x = a[i] + min(solve(i + 2, j, a), solve(i + 1, j - 1, a));
    int y = a[j] + min(solve(i, j - 2, a), solve(i + 1, j - 1, a));

    return dp[i][j] = max(x, y);
}

bool solve(vector<int>& candies) 
{
    int n = candies.size();
    
    dp[n][n];
    memset(dp, -1, sizeof(dp));
    int x = solve(0, n - 1, candies);

    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum += candies[i];
    }

    return x>(sum/2);
    
}