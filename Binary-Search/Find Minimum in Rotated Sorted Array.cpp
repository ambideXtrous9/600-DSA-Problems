#include <bits/stdc++.h>

using namespace std;

int findMin(vector<int> &nums)
{
    int n = nums.size();

    int l = 0;
    int h = n - 1;

    while (l <= h)
    {
        int m = (h - l) / 2 + l;

        int prev = (m - 1 + n) % n;
        int next = (m + 1) % n;

        if (nums[m] < nums[prev] && nums[m] < nums[next])
            return nums[m];

        else if (nums[m] > nums[h])
            l = m + 1;

        else
            h = m - 1;
    }

    return nums[l];
}