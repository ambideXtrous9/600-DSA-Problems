#include <bits/stdc++.h>

using namespace std;

vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{
    vector<long long int> ans(nums.size(), 1);
    long long int curr = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        ans[i] *= curr;
        curr *= nums[i];
    }
    curr = 1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        ans[i] *= curr;
        curr *= nums[i];
    }
    return ans;
}