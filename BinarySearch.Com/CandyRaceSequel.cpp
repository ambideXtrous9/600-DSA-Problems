#include <bits/stdc++.h>

using namespace std;

/*
You make your choice, then assume that the opponent will minimize your choice.
You maximize your turn, opponent will minimize your next turn -> for this candy problem.
So it all comes down to, after your pick, your 'next' pick will be minimized by the opponent.
*/

int dp1[100005][2];
int f(int ind, vector<int> &nums, int player)
{
    if (ind >= nums.size())
        return 0;

    if (dp1[ind][player] != -1)
        return dp1[ind][player];
    
    int ans = 0;

    if (player == 0) // player 1 tries to max his score
    {
        ans = max(ans, nums[ind] + f(ind + 1, nums, 1));

        if (ind + 1 < nums.size())
            ans = max(ans, nums[ind] + nums[ind + 1] + f(ind + 2, nums, 1));

        if (ind + 2 < nums.size())
            ans = max(ans, nums[ind] + nums[ind + 1] + nums[ind + 2] + f(ind + 3, nums, 1));
    }
    else
    {
        // player is 2 tries to minimize my score
        ans = INT_MAX;
        ans = min(ans, min(f(ind + 1, nums, 0), min(f(ind + 2, nums, 0), f(ind + 3, nums, 0))));
    }
    return dp1[ind][player] = ans;
}
bool solve(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0, ans = 0;
    memset(dp1, -1, sizeof(dp1));
    ans = f(0, nums, 0);
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    return ans > (sum / 2);
}