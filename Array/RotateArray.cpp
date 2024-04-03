#include <bits/stdc++.h>

using namespace std;

void rotate(vector<int> &nums, int k)
{

    int n = nums.size();
    deque<int> Q;

    for (auto x : nums)
    {
        Q.push_back(x);
    }

    k = k % n;

    // std::rotate(arr.begin(), arr.begin()+n-k, arr.end());

    for (int i = 0; i < k; i++)
    {
        int val = Q.back();
        Q.pop_back();
        Q.push_front(val);
    }

    for (int i = 0; i < n; i++)
        nums[i] = Q[i];
}