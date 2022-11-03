#include <bits/stdc++.h>

using namespace std;

/*
Algo:

1. LHS : prefsum
2. RHS : sum - prefsum + nums[i]
3. ans = max(LHS,RHS)
*/

int MaxTemp(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    for(auto x : nums) sum += x;

    int prefsum = 0;

    int ans = INT_MIN;

    for(int i = 0;i<n;i++)
    {
        prefsum += nums[i];

        int LHS = prefsum;
        int RHS = sum - prefsum + nums[i];

        ans = max({ans,LHS,RHS});

    }

    return ans;
}