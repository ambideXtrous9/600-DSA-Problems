#include <bits/stdc++.h>

using namespace std;
// Recursive (Backtracking)

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> subs;
    vector<int> sub;
    subsets(nums, 0, sub, subs);
    return subs;
}

void subsets(vector<int> &nums, int i, vector<int> &sub, vector<vector<int>> &subs)
{
    subs.push_back(sub);
    for (int j = i; j < nums.size(); j++)
    {
        sub.push_back(nums[j]);
        subsets(nums, j + 1, sub, subs);
        sub.pop_back();
    }
}

// Iterative
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> subs = {{}};
    for (int num : nums)
    {
        int n = subs.size();
        for (int i = 0; i < n; i++)
        {
            subs.push_back(subs[i]);
            subs.back().push_back(num);
        }
    }
    return subs;
}

// Bit Manipulation

// check ith bit is set or not (n & (1 << (k - 1)))

vector<vector<int>> subsets(vector<int> &nums)
{
    int n = nums.size(), p = 1 << n;
    vector<vector<int>> subs;
    for (int i = 0; i < p; i++)
    {
        vector<int> K;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                K.push_back(nums[j]);
            }
        }
        subs.push_back(K);
    }
    return subs;
}