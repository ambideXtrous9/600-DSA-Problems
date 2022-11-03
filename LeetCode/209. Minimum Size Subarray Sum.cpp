#include <bits/stdc++.h>

using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int i = 0;
    int j = 0;
    int sum = 0;
    int ans = INT_MAX;
    int n = nums.size();
    while (j < n)
    {
        sum += nums[j];
        if (sum < target && j < n)
        {
            j++;
        }
        else if (sum == target)
        {
            int temp = j - i + 1;
            ans = min(ans, temp);
            j++;
        }
        else
        {
            while (sum >= target)
            {
                int temp = j - i + 1;
                ans = min(ans, temp);
                sum -= nums[i];
                i++;
            }
            j++;
        }
    }
    if (ans == INT_MAX)
        return 0;
    return ans;
}